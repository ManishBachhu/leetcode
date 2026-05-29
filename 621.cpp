class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> freq(26, 0);

        for(char task: tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        // Find the number of idle slots required
        int max_freq = freq[0] - 1;
        int idle_slots = k * max_freq;

        for(int i = 1; i < 26 && freq[i] > 0; i++) {
            idle_slots -= min(freq[i], max_freq);
        }

        if(idle_slots > 0)
            return tasks.size() + idle_slots;

        return tasks.size();
    }
};
