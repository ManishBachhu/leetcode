class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currMax = 0;
        for(int i = 0; i < nums.size() - 1; i++, currMax--) {
            currMax = max(currMax, nums[i]);
            if ( currMax <= 0) {
                return false;
            }
        }

        return true;
    }
};
