class Solution {
public:
    double myPow(double x, int n1) {
        double ans = 1;
        long n = n1;
        if(n < 0) {
            x = 1/x;
            n = -n;
        }

        while(n) {
            if(n%2) {
                ans *= x;
                n--;
            }
            x *= x;
            n = n/2;
        }
        return ans;
    }
};
