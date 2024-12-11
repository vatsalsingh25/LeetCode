class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // we can just faltten the matrix;
        int low = 0;
        int high = n*m-1;
        // from mid we will extract the location of current element; n = mid/m; m = mid%m;
        while(low<=high){
            int mid = (high+low)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            if(matrix[mid/m][mid%m]<=target) low=mid+1;
            else high = mid-1;
        }
        return false;
    }
};