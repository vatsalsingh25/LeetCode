class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        int num = 1;
        while(left <= right && top <= bottom){              //imp
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(ans.size()==n*m) break;
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(ans.size()==n*m) break;
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(ans.size()==n*m) break;
            for(int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;  
            if(ans.size()==n*m) break;
        }
        return ans;
    }
};