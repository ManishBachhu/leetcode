class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        else if (x < 4) return 1;

        int l = 0, r = x;

        while(l < r) {
            int mid = (l + r)/2;
            if(mid <= x / mid)
                l = mid + 1;
            else
                r = mid;
        }

        return (int) l-1;
    }
};
