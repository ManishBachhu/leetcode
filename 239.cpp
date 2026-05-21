class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i = 1;
        // Monotonic decreasing queue
        deque<int> dq{0};

        while (i < k) {
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }

        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        while (i < n) {
            if(dq.front() <= i - k)
                dq.pop_front();
            
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
