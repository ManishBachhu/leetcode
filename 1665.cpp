class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by delta increasing
        // This is because we want the least energy wasted at the end
        // keep adding energy required, or set to min 
        // energy - whichever is higher

        auto customSort = [](vector<int>& a, vector<int>&b) {
            return a[1] - a[0] < b[1] - b[0];
        };

        sort(tasks.begin(), tasks.end(), customSort);

        int ans = 0;
        for(auto task : tasks) {
            ans = max(ans + task[0], task[1]);
        }

        return ans;
    }
};
