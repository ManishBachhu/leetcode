class Solution {
public:
    void sortColors(vector<int>& nums) {
        // l indicates where 0 should go, r represents where 2 should go
        int l = 0, r = nums.size() - 1;

        for(int i = 0l; i < nums.size(); i++) {
            switch(nums[i]){
                case 0:
                    swap(nums[i], nums[l]);
                    l++;
                    break;
                case 2:
                    if(i < r) {
                        swap(nums[i], nums[r]);
                        r--; i--;
                    }
                    break;
            }
        }
    }
};
