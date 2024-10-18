class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects;
        int N = profits.size();
        for(int i = 0; i < N; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        multiset<int> available;
        int it = 0;
        while(k--) {
            while(it < N and w >= projects[it].first) {
                available.insert(projects[it].second);
                it++;
            }
            if(!available.size()) {
                return w;
            }
            w += *available.rbegin();
            available.erase(--available.end());
        }

        return w;
    }
};
