class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
        int x = 0;
        int y = 0;
        int hlast = n;
        int vlast = m;
        int hfirst = 0;
        int vfirst = 1;
        while(1){
            while(y<hlast){
                ans.push_back(matrix[x][y]);
                y++;
                if(y==hlast){
                    hlast-=1;
                    y--;
                    x++;
                }
            }
            if(ans.size()==n*m) break;
            while(x<vlast){
                ans.push_back(matrix[x][y]);
                x++;
                if(x==vlast){
                    vlast-=1;
                    x--;
                    y--;
                }
            }
            if(ans.size()==n*m) break;
            while(y>=hfirst){
                ans.push_back(matrix[x][y]);
                y--;
                if(y==hfirst-1){
                    hfirst+=1;
                    y++;
                    x--;
                }
            }
            if(ans.size()==n*m) break;
            while(x>=vfirst){
                ans.push_back(matrix[x][y]);
                x--;
                if(x==vfirst-1){
                    vfirst+=1;
                    x++;
                    y++;
                }
            }
            if(ans.size()==n*m) break;
        }
        return ans;
    }
};
// [ 1, 2, 3, 4],
// [ 5, 6, 7, 8],
// [ 9,10,11,12],
// [13,14,15,16]...