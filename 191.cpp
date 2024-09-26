class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n > 0) {
            ans += 1;
            n = n&(n - 1); // flips least significant set bit
        }
        return ans;
    }
};
