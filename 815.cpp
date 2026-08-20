class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        
        unordered_map<int, vector<int>> stop_mp; // stop -> buses

        int n = routes.size(), max_stop = 0;
        for(int i = 0; i < n; i++) {
            for(int stop : routes[i]) {
                stop_mp[stop].push_back(i);
                max_stop = max(max_stop, stop);
            }
        }

        vector<bool> vis(max_stop + 1), vis_routes(n + 1);
        vis[source] = true;
        queue<int> bfs;
        bfs.push(source);
        int ans = 1;
        while(bfs.size()) {
            int sz = bfs.size();
            while(sz--) {
                int stop = bfs.front();
                bfs.pop();
                for(int bus: stop_mp[stop]) {
                    if(!vis_routes[bus]) {
                        for(int x: routes[bus]) {
                            if(!vis[x]) {
                                if(x == target)
                                    return ans;
                                bfs.push(x);
                                vis[x] = true;
                            }
                        }
                        vis_routes[bus] = true;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};
