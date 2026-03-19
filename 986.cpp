class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n1 = A.size(), n2 = B.size(), i = 0, j = 0;

        while(i < n1 && j < n2) {
            int lo = max(A[i][0], B[j][0]), hi =  min(A[i][1], B[j][1]);
            if(lo <= hi)
                ans.emplace_back(vector<int>{lo, hi});

            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }

        return ans;

    }
};
