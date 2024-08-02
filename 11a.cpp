// O(NlogN) solution. O(N) solution exists.
class Solution {
public:
    int maxArea(vector<int>& height) {
        map<int, vector<int>> heightToIndex;
        for (int i = 0; i < height.size(); i++) {
            auto& indices = heightToIndex[height[i]];
            
            if (indices.size() <= 1) {
                indices.push_back(i);
            } else {
                indices[1] = i;
            }
        }

        int l = INT_MAX, r = INT_MIN, ans = 0;
        for(auto it = heightToIndex.rbegin(); it != heightToIndex.rend();
            it++) {
                int ht = it->first;
                int idx = it->second[0];
                l = min(l, idx);
                r = max(r, idx);

                if (it->second.size() > 1) {
                    int secondIdx = it->second[1];
                    r = max(secondIdx, r);
                }
                
                ans = max(ans, (r - l) * (ht));
                // cout << *it << " : " << l << " , " << r << endl;
        }

        return ans;
    }
};
