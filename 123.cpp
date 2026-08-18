class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> first(n, 0), second(n, 0);

        int lo = prices[0];
        for(int i = 1; i < n; i++) {
            if(lo > prices[i])
                lo = prices[i];

            first[i] = max(first[i - 1], prices[i] - lo);
        }

        int hi = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(hi < prices[i])
                hi = prices[i];

            second[i] = max(second[i + 1], hi - prices[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, first[i] + second[i]);
        }

        return ans;
    }
};
