class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mappings;

        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';

        for(auto b: s) {
            if(mappings.find(b) == mappings.end()) {
                stk.push(b);
                continue;
            }

            if(stk.empty())
                return false;
            
            char bx = stk.top();
            stk.pop();

            if(bx != mappings[b])
                return false;
        }

        return stk.empty();
    }
};
