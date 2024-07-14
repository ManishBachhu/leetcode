class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> alphabets;
        int l = 0, r = 0, max_len = 0;
        
        // if char is already present, move left pointer to next char of prev instance
        while(r < s.size()) {
            if(alphabets[s[r]] > 0) {
                l = max(alphabets[s[r]], l);
            }
            max_len = max(max_len, r-l+1);
            alphabets[s[r]] = r + 1;
            r++;
        }

        return max_len;
    }
};
