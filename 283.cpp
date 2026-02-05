class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, N = nums.size();

        while(i < N) {
            if(nums[i] == 0) {
                i++;
                continue;
            }
            nums[j] = nums[i];
            i++, j++;
        }

        while(j < N) {
            nums[j] = 0;
            j++;
        }
    }
};
