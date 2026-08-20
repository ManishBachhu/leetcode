class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        int maxStop = -1;
        if(source==target )return 0;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                maxStop = max(maxStop, routes[i][j]);
            }
        }
        if (target > maxStop || source>maxStop)
            return -1;
        int n = routes.size();
        vector<int> res(maxStop + 1, n + 1);
        res[source] = 0;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < routes.size(); i++) {
                int mini = n + 1;
                for (int j = 0; j < routes[i].size(); j++) {
                    mini = min(mini, res[routes[i][j]]);
                }
                mini++;
                for (int j = 0; j < routes[i].size(); j++) {
                    if (res[routes[i][j]] > mini) {
                        flag = true;
                        res[routes[i][j]] = mini;
                    }
                }
            }
        }
        return (res[target] < n + 1 ? res[target] : -1);
    }
};
