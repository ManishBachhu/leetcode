class Solution {
public:
    int minimumDeletions(string s) {
        int count_a = 0, n = s.size(), count_b = 0, ans = INT_MAX;

        for(auto x : s) {
            if(x == 'a')
                count_a++;
        }

        for(auto x: s) {
            if(x == 'a')
                count_a--;
            // deletions required at ith pos is all a's on the right
            // and all the b's to the left
            ans = min(ans, count_a + count_b);
            if(x == 'b') count_b++;
        }

        return ans;
    }
};
