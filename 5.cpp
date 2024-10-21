class Solution {
public:
    int expand(string &s, int l, int r) {
        /* Length of the longest palindrome centered at l, r */
        int len = r - l + 1;
        while (l > 0 && r < s.size()) {
            l--, r++;
            if(s[l] != s[r])
                break;
            len += 2;
        }
        return len;
    }

    string longestPalindrome(string s) {
        int N = s.size();
        string ans;
        // Odd len palindromes
        for(int i = 0; i < N; i++) {
            int len = expand(s, i , i);
            if(len > ans.size()) {
                ans = s.substr(i - (len/2), len);
            }
        }

        // Even len palindromes
        for(int i = 0; i < N - 1; i++) {
            if(s[i] == s[i+1]) {
                int len = expand(s, i , i + 1);
                if(len > ans.size()) {
                    ans = s.substr(i - (len/2) + 1, len);
                }
            }
        }

        return ans;


    }
};
