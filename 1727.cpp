class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size(), ans = 0;
        vector<pair<int, int>> prevHeights; // ht, col

        for(int r = 0; r < R; r++) {
            vector<pair<int,int>> currHeights;
            vector<bool> seen(C, false);

            // add cols to currHeights where increase is possible
            for(int i = 0; i < prevHeights.size() && r > 0; i++) {
                int h = prevHeights[i].first, c = prevHeights[i].second;
                if(matrix[r][c] > 0) {
                    currHeights.push_back(pair<int,int>{h + 1, c});
                }
                seen[c] = true;
            }

            // add new cols to currHeights
            for(int c = 0; c < C; c++) {
                if(!seen[c] && matrix[r][c] > 0) {
                    currHeights.push_back(pair<int,int>{1, c});
                }
            }

            // update max area of submatrix
            for(int i = 0; i < currHeights.size(); i++) {
                int h = currHeights[i].first;
                // area = height x width
                ans = max(ans, h*(i + 1));
            }

            prevHeights = currHeights;
        }

        return ans;
    }
};
