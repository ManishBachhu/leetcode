//O(n^2) solution using DP

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, INT_MAX);
        jumps[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= nums[i] && i + j < n; j++) {
                if(jumps[i + j] == INT_MAX) continue;
                jumps[i] = min(jumps[i], 1 + jumps[i + j]);
            }
        }
        return jumps[0];
    }
};
