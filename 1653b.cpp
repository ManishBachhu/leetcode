class Solution {
public:
    int minimumDeletions(string s) {
        // DP approach:
        int n = s.size(), count_a = 0, len = 0, del = 0;

        for(int i = 0; i < n; i++) {
            // b can always be appended at the end to increase length
            if(s[i] == 'b') {
                len++;
                continue;
            }
            count_a++;

            // The idea is to replace b's from string with a
            // Every replacement is counted as a deletion
            // If we can't do replacement, then we should append
            if(count_a <= len) {
                del++;
            } else {
                len++;
            }
        }

        return del;
    }
};
