class Solution {
    vector<vector<int>> combs;
public:
    void backtrack(int n, int k, int firstNum, vector<int> &nums) {
        if(nums.size() == k) {
            combs.push_back(nums);
            return;
        }

        int need = k - nums.size();
        int remain = n - firstNum + 1;
        int available = remain - need;
        
        for(int curr = firstNum; curr <= firstNum + available; curr++) {
            nums.push_back(curr);
            backtrack(n, k, curr + 1, nums);
            nums.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        backtrack(n, k, 1, nums);
        return combs;
    }
};
