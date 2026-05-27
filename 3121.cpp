class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> last_low(26, INT_MAX), first_up(26, -1);

        for(int i = 0; i < n; i++) {
            if(islower(word[i])) {
                last_low[word[i] - 'a'] = i;
            } else {
                if(first_up[word[i] - 'A'] == -1)
                    first_up[word[i] - 'A'] = i;
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(last_low[i] < first_up[i])
                ans++;
        }

        return ans;
    }
};
