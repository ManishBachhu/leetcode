class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> dq; // Store the indices
        vector<int> ans(prices.size(), 0);
        for(int i = 0; i < prices.size(); i++) {
            if(!dq.size() || prices[i] > prices[dq.top()]) {
                dq.push(i);
            } else {
                while(dq.size() && prices[i] <= prices[dq.top()]) {
                    auto x = dq.top();
                    dq.pop();
                    ans[x] = prices[x] - prices[i];
                }
                dq.push(i);
            }
        }
        while(dq.size()) {
            int x = dq.top();
            dq.pop();
            ans[x] = prices[x];
        }

        return ans;
    }
};
