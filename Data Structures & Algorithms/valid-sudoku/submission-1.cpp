class Solution {
public:
    bool checkNums(vector<vector<char>> & board) {
        int n = board.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != '.' && (board[i][j] > '9' || board[i][j] < '0'))
                    return false;
            }
        }
        return true;
    }

    bool checkVertical(vector<vector<char>> & board) {
        int n = board.size();
        for(int i = 0; i < n; ++i) {
            vector<bool> v(10, false);
            for(int j = 0; j < n; ++j) {
                if(board[j][i] == '.') continue;
                if(v[board[j][i] - '0']) return false;
                else v[board[j][i] - '0'] = true;
            }
        }
        return true;
    }

    bool checkHorizontal(vector<vector<char>> & board) {
        int n = board.size();
        for(int i = 0; i < n; ++i) {
            vector<bool> v(10, false);
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '.') continue;
                if(v[board[i][j] - '0']) return false;
                v[board[i][j] - '0'] = true;
            }
        }
        return true;
    }

    bool checkGrids(vector<vector<char>> & board) {
        int n = board.size();
        for(int i = 0; i < n; i+=3) {
            for(int j = 0; j < n; j+=3) {
                vector<bool> v(10, false);
                for(int k = i; k < i+3; k++) {
                    for(int l = j; l < j+3; l++) {
                        if(board[k][l] == '.') continue;
                        if(v[board[k][l] - '0']) return false;
                        v[board[k][l] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool numsOnly = checkNums(board);
        bool vertical = checkVertical(board);
        bool horizontal = checkHorizontal(board);
        bool grids = checkGrids(board);
        return(numsOnly && vertical && horizontal && grids);
    }
};