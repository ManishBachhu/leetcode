class Solution {
public:
    int minJumps(vector<int>& arr) {
        /*
        Approach:
        - Use BFS to find the shortest path to last node
        */

        int n = arr.size();
        unordered_map<int,vector<int>> nodes;

        for(int i = 0; i < n; i++) {
            nodes[arr[i]].push_back(i);
        }

        // Do BFS to get min path
        int target = n - 1, min_jumps = 0;
        queue<int> node_q;
        vector<bool> visited(n);
        node_q.push(0);
        visited[0];
        
        while(!node_q.empty()) {
            int size = node_q.size();

            while(size--) {
                int curr = node_q.front();
                node_q.pop();
                if(curr == target)
                    return min_jumps;
                
                if(curr >= 1 && !visited[curr - 1]) {
                    node_q.push(curr - 1);
                    visited[curr - 1] = true;
                }

                if(curr < n - 1 && !visited[curr + 1]) {
                    node_q.push(curr + 1);
                    visited[curr + 1] = true;
                }


                for(auto node: nodes[arr[curr]]) {
                    if(!visited[node] && 
                            (node < curr - 1 || node > curr + 1)) {
                        node_q.push(node);
                        visited[node] = true;
                    }
                }
                nodes.erase(arr[curr]);
            }

            min_jumps++;
        }

        return min_jumps;
    }
};
