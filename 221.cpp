class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int R = matrix.size(), C = matrix[0].size(), ans = 0;
        vector<vector<int>> grid(R, vector<int>(C, 0));

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(matrix[i][j] == '0')
                    continue;

                // max size = min(left, up, diag) + 1
                int x = (i >= 1)?grid[i-1][j]:0;
                int y = (j >= 1)?grid[i][j-1]:0;
                int diag = (i >= 1 && j >= 1)?grid[i-1][j-1]:0;

                grid[i][j] = min(min(x,y), diag) + 1;
                ans = max(ans, grid[i][j]);
            }
        }

        return ans*ans;
    }
};
