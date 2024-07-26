class Solution {
public:
    bool isValid(string s) {
        /*
        * Iterate through string.
        * if left bracket: add to stack.
        * if right: pop stack. If not matching left, return false;
        * if stack is empty, return true
        */ 
        stack<char> brackets;
        unordered_map<char, char> mappings;
        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';

        for(auto br : s) {
            if (mappings.find(br) != mappings.end()) {
                //closing bracket
                if (brackets.empty())
                    return false;

                char br2 = brackets.top();
                if (mappings[br] != br2) {
                    return false;
                }
                brackets.pop();
            }
            else {
                // opening bracket
                brackets.push(br);
            }
        }

        if (brackets.size() != 0)
            return false;

        return true;
    }
};
