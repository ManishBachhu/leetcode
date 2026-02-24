class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window; // count of char within window
        unordered_map<char, int> need;   // min req count for each char
        int formed = 0, minLen = INT_MAX;
        queue<int> pos;

        for(auto ch: t) {
            need[ch]++;
        }
        
        int left = 0, right = 0, n = s.size(), reqLen = t.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(need.find(s[i]) != need.end()) {
                right = i;
                window[s[i]]++;
                if(window[s[i]] <= need[s[i]])
                    formed++;
                pos.push(i);

                if(need.find(s[left]) == need.end())
                    left = i;

                while(formed == reqLen && window[s[left]] > need[s[left]]) {
                    window[s[left]]--;
                    pos.pop();
                    left = pos.front();
                }

                if(formed == reqLen && minLen > right - left + 1) {
                    minLen = right - left + 1;
                    ans = s.substr(left, minLen);
                }
            }
        }

        return ans;
    }
};
