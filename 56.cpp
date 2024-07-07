class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals based on the first element
        // create a new vector to store the result
        // iterate through the intervals
        // if the res vector is empty, push the current interval
        // if the last element of the res vector is less than the first 
        //   element of the current interval, push the current interval
        // else, update the last element of the res vector with the max of
        //   the last element of the res vector and the last element of the
        //   current interval
        // return the res vector

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto vec: intervals){
            if(res.empty() || res.back()[1] < vec[0]){
                res.push_back(vec);
            }else{
                res.back()[1] = max(res.back()[1], vec[1]);
            }
        }
        return res;
    }
};