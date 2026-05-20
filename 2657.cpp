class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), next = n;
        vector<int> ans(n);
        vector<bool> seen(n + 1);

        // Number is counted in answer only after the second time its seen
        // So in reverse, we can decrement the counter the first time its seen
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = next;
            if(!seen[A[i]]) {
                next--;
                seen[A[i]] = true;
            }
            if(!seen[B[i]]) {
                next--;
                seen[B[i]] = true;
            }
        }

        return ans;
    }
};
