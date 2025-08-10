class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int n = v.size();
        vector<int> p(n + 1, INT_MAX);
        for (int i = 1; i <= n; ++i)
            p[i] = min(p[i - 1], v[i - 1]);
        stack<int> right;
        right.push(INT_MAX);
        bool ans = false;
        for (int i = n - 1; i > 0 and not ans; --i) {
            while (right.top() <= p[i])
                right.pop();
            if (v[i] > right.top())
                ans = true;
            right.push(v[i]);
        }
        return ans;
    }
};
