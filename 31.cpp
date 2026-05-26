class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /* Find the pivot element - first element smaller than its next from the right
         * Replace it with the next highest number following it
         * Reverse all the elements following the pivot element
         */

        int n = nums.size();
        if(n == 1)
            return;
        
        int pivot = n - 2;

        while(pivot >= 0 && nums[pivot] >= nums[pivot + 1] ) {
            pivot--;
        }

        // Swap with next biggest num after pivot
        if(pivot >= 0) {
            int i = n - 1;
            while(nums[pivot] >= nums[i]) {
                i--;
            }
            swap(nums[pivot], nums[i]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
