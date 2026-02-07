class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freqMap;
        int maxFreq = 0, start = 0, end = 1;
        for(auto ch: s) {
            freqMap[ch]++;
            maxFreq = max(maxFreq, freqMap[ch]);
            // if current length is not possible with the subs available
            if(end - start - maxFreq > k) {
                // Remove the last letter
                freqMap[s[start]]--;
                start++;
            }
            end++;
        }
        
        return end - start - 1;
    }
};
