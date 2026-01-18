class Solution {
    vector<string> ans;
public:
    void addCombinations(int N, string comb, int stk, int n) {
        if(comb.size() == 2*N) {
            ans.push_back(comb);
            return;
        }

        if(n) {
            stk++;
            n--;
            comb += '(';
            addCombinations(N, comb, stk, n);
            comb.pop_back();
            n++;
            stk--;
        }

        if(stk) {
            stk--;
            comb += ')';
            addCombinations(N, comb, stk, n);
            comb.pop_back();
        }
    } 
    vector<string> generateParenthesis(int N) {
        addCombinations(N,  // total number of braces sets to use
                        "", // current combination
                        0,  // number of open braces in the stack
                        N   // number of open braces to left to add
        );

        return ans;
    }
};
