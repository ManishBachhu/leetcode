class Solution {
public:
    int minOperations(int n) {
        int ops = 0, consecutiveOnes = 0;
        while(n) {
            // cout << n;
            if(n%2) {
                consecutiveOnes++;
                n >>= 1;
            }
            else {
                n >>= 1;
                if(consecutiveOnes == 0) {
                    continue;
                } else if(consecutiveOnes == 1) {
                    // subtract 2^n
                    ops++;
                } else {
                    // add 2^n
                    ops++;
                    n <<= 1;
                    n++;
                }
                consecutiveOnes = 0;
            }
        }
        if(consecutiveOnes == 1)
            ops++;
        else if(consecutiveOnes > 1)
            ops += 2;

        return ops;
    }
};
