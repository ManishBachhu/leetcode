// Time Complexity: O(N^2) - 3 pass
// Space Complexity: O(1)
class Solution {
public:
    const int N = 9;
    bool isDuplicate(char ch, int* pNum) {
        int x = ch - '1', num = *pNum, mask = 1 << x;

        // if num is already seen before
        if (num & mask) {
            return true;
        }
        *pNum = num | mask;
        return false;
    }

    bool isValidRow(vector<char>& row) {
        // Use bitmask to check duplicates
        int num = 0;
        int* pNum = &num;
        for(auto ch: row) {
            if(ch != '.' && isDuplicate(ch, pNum)) {
                return false;
            }
        }
        return true;
    }

    bool isValidColumn(vector<vector<char>>& board, int col) {
        int num = 0;
        int* pNum = &num;
        for(int i = 0; i < N; i++) {
            char ch = board[i][col];
            if(ch != '.' && isDuplicate(ch, pNum)) {
                return false;
            }
        }
        return true;
    }

    bool isValidBox(vector<vector<char>>& board, int row, int col) {
        int num = 0;
        int* pNum = &num;
        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {
                char ch = board[i][j];
                if(ch != '.' && isDuplicate(ch, pNum)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate rows
        for(auto row: board) {
            if(!isValidRow(row)) {
                return false;
            }
        }

        //Validate columns
        for(int j = 0; j < N; j++) {
            if(!isValidColumn(board, j)) {
                return false;
            }
        }

        //Validate boxes
        for(int i = 0; i < N; i += 3) {
            for(int j = 0; j < N; j += 3) {
                if(!isValidBox(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};
