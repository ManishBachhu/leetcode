class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<int> ans;
        ans.reserve(R * C);

        // Process each diagonal directly without intermediate storage
        for(int sum = 0; sum < R + C - 1; sum++) {
            if(sum % 2 == 0) {
                // Even diagonal: traverse bottom-left to top-right
                for(int r = min(sum, R - 1); r >= 0 && sum - r < C; r--) {
                    ans.push_back(mat[r][sum - r]);
                }
            } else {
                // Odd diagonal: traverse top-right to bottom-left
                for(int r = max(0, sum - C + 1); r < R && r <= sum; r++) {
                    ans.push_back(mat[r][sum - r]);
                }
            }
        }

        return ans;
    }
};
