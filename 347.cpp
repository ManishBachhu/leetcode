class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(auto x: nums) {
            freq[x]++;
        }

        auto comp = [&freq](int a, int b) {
            return freq[a] > freq[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto p: freq) {
            pq.push(p.first);
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
