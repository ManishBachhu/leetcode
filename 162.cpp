class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n;
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(mid == n - 1 || nums[mid] > nums[mid + 1])
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
