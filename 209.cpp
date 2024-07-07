class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, minLength = INT_MAX, sum = 0;

        while(true) {
            // cout << sum << endl;
            if(sum < target) {
                if(r == nums.size()) break;
                sum += nums[r];
                r++;
            }
            else {
                minLength = min(minLength, r-l);
                sum -= nums[l];
                l++;
            }
        }
        if(minLength == INT_MAX) return 0;
        return minLength;
    }
};