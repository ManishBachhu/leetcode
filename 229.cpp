class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting algorithm
        int count1 = 0, count2 = 0,  x1 = 0, x2 = 0;
        for(auto num: nums) {
            if(x1 == num) {
                count1++;
            } else if(x2 == num) {
                count2++;
            } else if(count1 == 0) {
                count1++;
                x1 = num;
            } else if(count2 == 0) {
                count2++;
                x2 = num;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(auto num: nums) {
            if(x1 == num)
                count1++;
            else if(x2 == num)
                count2++;
        }
        
        vector<int> ans;
        int n = nums.size();
        if(count1 > n/3)
            ans.push_back(x1);
        if(count2 > n/3)
            ans.push_back(x2);
        
        return ans;
    }
};
