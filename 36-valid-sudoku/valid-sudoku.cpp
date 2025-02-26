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
        for (int i = 0; i < 9; i++) {  // Iterate over 3x3 boxes (0 to 8)
            int boxRow = (i / 3) * 3;  // Top-left row of the box
            int boxCol = (i % 3) * 3;  // Top-left col of the box

            map<char,int>hash;
            for (int j = 0; j < 9; j++) {  // Traverse inside the box
                int row = boxRow + (j / 3);  // Row inside the box
                int col = boxCol + (j % 3);  // Col inside the box
                hash[board[row][col]]++;
            }
            for(auto it: hash){
                if(it.first!='.' && it.second>1) return false;
            }
        }
        return true;
    }
};