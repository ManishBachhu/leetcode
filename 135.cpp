class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // Create two arrays init to 1
        vector<int> candies(n, 1); 
        // First array is l-r increasing val
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        // Second is r-l increasing val
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};