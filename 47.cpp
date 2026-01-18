class Solution {
    vector<vector<int>> ans;
    unordered_map<int, int> counter;
public:
    void addPermutations(vector<int>& comb, int N) {
        if(comb.size() == N) {
            ans.push_back(comb);
            return;
        }

        for(auto it: counter) {
            if(it.second) {
                comb.push_back(it.first);
                counter[it.first]--;
                addPermutations(comb, N);
                counter[it.first]++;
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int num : nums)
            counter[num]++;
        vector<int>comb = {};
        addPermutations(comb, nums.size());
        return ans;
    }
};
