/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    int poolSize = 8; // Concurrency pool limit
    
    // Variables that need to be handled only under lock
    mutex mtx;
    condition_variable cv;
    unordered_set<string> urlSet;
    queue<string> unprocessedUrls;
    int currentlyWorking = 0;
    bool done = false;

    string getHostname(string& url) {
        // Assume all urls start with http:// which is 7 characters long
        size_t hostnameStart = 7;

        size_t hostnameEnd = url.find('/', hostnameStart);
        if(hostnameEnd == string::npos) {
            hostnameEnd = url.length();
        }

        return url.substr(hostnameStart, hostnameEnd - hostnameStart);
    }

    bool isSameHostname(string& url, string& hostname) {
        return hostname == getHostname(url);
    }

    string getUnprocessedUrl() {
        currentlyWorking++; // Mark that a worker is processing url
        string url = unprocessedUrls.front();
        unprocessedUrls.pop();
        return url;
    }
    
    void endProcess(vector<string> urls, string& hostname) {
        lock_guard<mutex> lock(mtx);
        for(auto url : urls) {
            if(isSameHostname(url, hostname) && urlSet.insert(url).second == true) {
                unprocessedUrls.push(url);
            }
        }

        currentlyWorking--; // update that worker is finished

        // Mark exit condition if all threads finished processing and there is no more work
        if(currentlyWorking == 0 && unprocessedUrls.empty()) {
            done = true;
            cv.notify_all();
        }
    }
    
    void doWork(HtmlParser& htmlParser, string& hostname) {
        while(true) {
            string url;
            {
                // get from queue
                unique_lock<mutex> lock(mtx);
                // Wait if no new tasks are present and processing is not complete.
                cv.wait(lock, [this] {
                    return !unprocessedUrls.empty() || done;
                });

                // Exit condition if queue is empty
                if (done) {
                    return; // Worker ends execution
                }

                url = getUnprocessedUrl();
            }
            // parse urls
            vector<string> urls = htmlParser.getUrls(url);
            // add to queue
            endProcess(move(urls), hostname);
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string hostname = getHostname(startUrl);
        unprocessedUrls.push(startUrl);
        urlSet.insert(startUrl);
        
        vector<thread> workerPool;

        for(int i = 0; i < poolSize; i++) {
            workerPool.emplace_back([this, &htmlParser, &hostname](){
                doWork(htmlParser, hostname);
            });
        }

        for(auto& worker : workerPool) {
            worker.join();
        }

        return vector<string>(urlSet.begin(), urlSet.end());
    }
};
