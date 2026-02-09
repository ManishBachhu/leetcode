class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int N = arr.size();
        unordered_set<int> ans, res{0};

        for(auto num: arr) {
            unordered_set<int> curr; // add new results here
            // OR with already existing results
            // Better than linear O(N) since duplicates are removed
            for(auto x: res) 
                curr.insert(x | num);
            // Add the new num (if not seen before)
            curr.insert(num);
            // insert the new ones 
            ans.insert(curr.begin(), curr.end());
            res = curr;
            
        }

        return ans.size();
    }
};
