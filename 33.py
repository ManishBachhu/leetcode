class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Search for the lowest element
        // use that as base for bin search indexes
        int n = nums.size(), lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }
        // cout << lo;
        int k = lo;
        hi = n + k;

        while(lo < hi) {
            int mid = (lo + (hi - lo)/2);
            if(nums[mid % n] < target)
                lo = mid + 1;
            else
                hi = mid;
        }

        return (nums[lo % n] == target)?(lo % n):-1;
    }
};
