class Solution {
public:
    int trap(vector<int>& height) {
        // Calculate max heights from l-r and r-l
        // Min of maxHeight at each point makes the canopy
        // Water area = canopy area - blocked area
        vector<int> canopy;
        int blockedArea = 0, ht = 0, n= height.size();
        for(int i = 0; i < n; i++) {
            blockedArea += height[i];
            ht = max(ht, height[i]);
            canopy.push_back(ht);
        }

        ht = 0;
        int canopyVolume = 0;
        for(int i = n- 1; i >= 0; i--) {
            ht = max(ht, height[i]);
            canopyVolume += min(ht, canopy[i]);
        }

        return canopyVolume - blockedArea;
    }
};
