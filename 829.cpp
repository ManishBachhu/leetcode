class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0, c = 0;

        // n = k.x + k(k-1)/2 --> sum of 0 -> k
        // solve for interger x
        for(int k = 1; c < n; k++) {
            if((n-c)%k == 0)
                ans++;

            c += k;
        }

        return ans;
        
    }
};
