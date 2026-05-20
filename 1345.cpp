class Solution {
public:
    int minJumps(vector<int>& arr) {
        /*
        Approach:
        - Use BFS to find the shortest path to last node
        */

        int n = arr.size();
        unordered_map<int, vector<int>> val_to_index;

        for (int i = 0; i < n; i++) {
            val_to_index[arr[i]].push_back(i);
        }

        // Do BFS to get min path
        int target = n - 1, min_jumps = 0;
        queue<int> bfs_q;
        vector<bool> visited(n);
        bfs_q.push(0);
        visited[0];

        while (!bfs_q.empty()) {
            int size = bfs_q.size();

            while (size--) {
                int curr = bfs_q.front();
                bfs_q.pop();
                if (curr == target)
                    return min_jumps;

                if (curr >= 1 && !visited[curr - 1]) {
                    bfs_q.push(curr - 1);
                    visited[curr - 1] = true;
                }

                if (curr < n - 1 && !visited[curr + 1]) {
                    bfs_q.push(curr + 1);
                    visited[curr + 1] = true;
                }

                for (auto node : val_to_index[arr[curr]]) {
                    if (!visited[node] &&
                        (node < curr - 1 || node > curr + 1)) {
                        bfs_q.push(node);
                        visited[node] = true;
                    }
                }
                val_to_index.erase(arr[curr]);
            }

            min_jumps++;
        }

        return min_jumps;
    }
};
