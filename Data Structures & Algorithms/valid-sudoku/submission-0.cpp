class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> check;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (check.find(board[row][col]) != check.end()) {
                    return false;
                } else {
                    check.insert(board[row][col]);
                }
            }
        }
        for (int col = 0; col < 9; col++) {
            unordered_set<char> check;

            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (check.find(board[row][col]) != check.end()) {
                    return false;
                } else {
                    check.insert(board[row][col]);
                }
            }
        }
        for(int boxrow = 0; boxrow<9; boxrow+=3){
            for(int boxcol = 0; boxcol<9; boxcol+=3){
                unordered_set<int> check;
                for(int row=boxrow; row<boxrow+3; row++){
                    for(int col=boxcol; col<boxcol+3;col++ ){
                        if(board[row][col]=='.'){
                            continue;
                        }
                        if(check.find(board[row][col]) != check.end()){
                            return false;
                        }
                        else{
                            check.insert(board[row][col]);
                        }
                    }
                }
            }
        }
        return true;
    }
};