class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate row
        for(int i=0; i<9; i++){
            map<char,int>hash;
            for(int j=0; j<9; j++){
                hash[board[i][j]]++;
            }
            for(auto it: hash){
                if(it.first!='.' && it.second>1) return false;
            }
        }
        //validate col
        for(int i=0; i<9; i++){
            map<char,int>hash;
            for(int j=0; j<9; j++){
                hash[board[j][i]]++;
            }
            for(auto it: hash){
                if(it.first!='.' && it.second>1) return false;
            }
        }
        //validate box
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {  // Iterate over 3x3 box rows
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {  // Iterate over 3x3 box cols
                map<char,int>hash;
                // Traverse elements inside the current 3x3 box
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = boxRow + i;
                        int col = boxCol + j;
                        hash[board[row][col]]++;
                    }
                }
                for(auto it: hash){
                    if(it.first!='.' && it.second>1) return false;
                }
            }
        }
        return true;
    }
};