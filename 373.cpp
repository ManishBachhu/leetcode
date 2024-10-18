class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        int N = nums1.size(), M = nums2.size();

        // Push the first column of pairs (nums1[i], nums2[0])
        for (int i = 0; i < N; ++i) {
            pq.emplace(i, 0);
        }

        vector<vector<int>> ans;
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            
            // If there's a next pair in the row (nums1[i], nums2[j+1]), push it
            if (j + 1 < M) {
                pq.emplace(i, j + 1);
            }
        }

        return ans;
    }
};
