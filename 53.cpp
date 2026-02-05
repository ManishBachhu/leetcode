class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> cummSum{0};
        int sum = 0;
        for(int num: nums) {
            sum += num;
            cummSum.push_back(sum);
        }

        int l = 0, r = 1, n = nums.size(), maxSum = cummSum[1];
        while(r <= n) {
            maxSum = max(cummSum[r] - cummSum[l], maxSum);
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            if(cummSum[r] - cummSum[l] <= 0) {
                l = r;
            }
            r++;
        }

        return maxSum;
    }
};
