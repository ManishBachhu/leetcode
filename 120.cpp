// DP Bottom up
// Time Complexity : O(N^2), Space Complexity : O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<int> currRow = triangle[N - 1];

        for(int i = N - 2; i >= 0; i--) {
            vector<int> prevRow = currRow;
            currRow.resize(i + 1);
            for(int j = 0; j <= i; j++) {
                currRow[j] = min(prevRow[j], prevRow[j + 1]) + triangle[i][j];
            }
        }

        return currRow[0];
    }
};
