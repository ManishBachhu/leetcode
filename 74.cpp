class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size();

        // Get row
        while(lo < hi) {
            int mid = (lo + hi)/2;
            if(matrix[mid][0] <= target)
                lo = mid + 1;
            else
                hi = mid;
        }

        int row = max(0, lo - 1), n = matrix[row].size();
        lo = 0, hi = n;

        // Get col
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(matrix[row][mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        int col = min(n - 1, lo);

        return matrix[row][col] == target;
    }
};
