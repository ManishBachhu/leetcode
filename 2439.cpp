class Solution {
    // this is a custom ceil function
    static inline int cdiv(long x, int y) {
        return x / y + bool(x % y);
    }
public:
    int minimizeArrayValue(vector<int>& v) {
        long sum = 0;
        int n = v.size(), ans = 0;
        for (int i = 0; i < n; ++i)
            sum += v[i], ans = max(ans, cdiv(sum, i + 1));
        return ans;
    }
};
