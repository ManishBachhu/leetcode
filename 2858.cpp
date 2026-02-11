class Solution {
    vector<vector<int>> g, gn; // adj graph, rev graph
    vector<int> ans, dp;

    int dfs(int u, vector<bool>& vis) {
        if(vis[u])
            return 0;
        vis[u] = true;
        int sum = 0;

        for(auto v: g[u]) {
            sum += dfs(v, vis);
        }

        for(auto v: gn[u]) {
            if(!vis[v]) {
                sum += dfs(v, vis);
                sum++;
            }
        }
        return sum;
    }

    void dfs2(int u, vector<bool>& vis) {
        if(vis[u])
            return;
        vis[u] = true;

        for(auto v: g[u]) {
            // We have edge from u->v
            // So if v is the root, we need to reverse this edge
            // Cost is +1 due to that
            ans[v] = ans[u] + 1;
            dfs2(v, vis);
        }

        for(auto v: gn[u]) {
            // We have edge from u<-v
            // So if v is the root, we don't need to reverse this edge
            // Cost is -1 due to that
            ans[v] = ans[u] - 1;
            dfs2(v, vis);
        }
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        g.resize(n + 1);
        gn.resize(n + 1);
        ans.resize(n, -1);
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
            gn[v].push_back(u);
        }

        // Get ans 0th node
        vector<bool> vis(n);   
        ans[0] = dfs(0, vis);

        // Re-root to other nodes
        // when we go to a neighbour with a directed edge:
        // we have to reverse that edge to go back to our parent, so do cnt + 1.

        // when we go to a neighbour with a reversed directed edge:
        // we need to decrease the counter because we no longer need to pay for that edge, so do cnt - 1.

        vis = vector<bool>(n);
        dfs2(0, vis);

        return ans;
    }
};
