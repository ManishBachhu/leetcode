class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strs(n);
        for(int i = 0; i < n; i++) {
            strs[i] = to_string(nums[i]);
        }

        auto customSort = [](string& a, string& b) {
            return a+b > b+a;
        };

        sort(strs.begin(), strs.end(), customSort);
        string ans;
        for(auto st: strs) {
            ans += st;
        }

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};
