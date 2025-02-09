class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> arr(n,vector<int>(n,0));

        // top-right triangle
        for(int x=1; x<n; x++){               //traversing row
            int i = 0;
            int j = x;

            vector<int>temp;                    //temp array to store diagonal elements

            while(i<n && j<n){                  //diagonal elements can be traversed by i+1,j+1 and add to temp       
                temp.push_back(grid[i][j]);    
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());    //sort so that it can be added to the answer array
            i=0;
            j=x;
            while(i<n && j<n){               //traverse the same way as above and take values from temp array
                arr[i][j]=temp[i];
                i++;
                j++;
            }            
        }     

        // bottom-left triangle
        for(int y=0; y<n; y++){              //traversing column
            int j=0;
            int i=y;
            vector<int>temp;
            while(i<n && j<n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end(), greater<int>());
            j=0;
            i=y;
            while(i<n && j<n){
                arr[i][j]=temp[j];
                i++;
                j++;
            }            
        }

        return arr;   
    }
};