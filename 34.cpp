class Solution {
public:
    int getLowerIndex(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, res = -1;
        while(l < r) {
            int mid = (l+r)/2;
            if(nums[mid] >= target) {
                if(nums[mid] == target) res = mid;
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }

    int getUpperIndex(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, res = -1;
        while(l < r) {
            int mid = (l+r+1)/2;
            if(nums[mid] <= target) {
                if(nums[mid] == target) res = mid;
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{
            getLowerIndex(nums, target),
            getUpperIndex(nums, target)};
    }
};
