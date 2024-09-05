// O(N) greedy solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int currJumpRange = 0, jumps = 0, maxDepth = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxDepth = max(maxDepth, i + nums[i]);
            if(currJumpRange == 0) {
                jumps++;
                currJumpRange = maxDepth - i;
            }
            currJumpRange--;
        }
        return jumps;
    }
};
