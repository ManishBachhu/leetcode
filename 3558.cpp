class Solution {
public:
    int qpow(long long a, int b, int MOD) {
        long long res = 1;
        while(b) {
            if(b & 1) {
                res *= a; 
                res %= MOD;
            }
            a *= a;
            a %= MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        // DFS/BFS to get max depth n
        // nc1 + nc3 + nc5 ... ncn to get all combinations
        // Sum of above is 2^(n - 1)

        int n = edges.size() + 1;
        vector<vector<int>> tree(n + 1, vector<int>());

        for(auto& e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        deque<int> dq;
        dq.push_back(1);
        int depth = 0, count = 1;
        vector<bool> visited(n + 1);
        visited[1] = true;

        while(!dq.empty()) {
            int new_count = 0;
            while(count--) {
                int x = dq.front();
                dq.pop_front();
                
                for(int i = 0; i < tree[x].size(); i++) {
                    int y = tree[x][i];
                    if(!visited[y]) {
                        dq.push_back(y);
                        visited[y] = true;
                        new_count++;
                    }
                }
            }
            depth++;
            count = new_count;
        }

        const int MOD = 1e9 + 7;

        return qpow(2, depth - 2, MOD);
    }
};
