class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;            // (m-1) right steps +(n-1) downward steps we must take to reach the end
        int r = m-1;
        double ans = 1;
        for(int i=0; i<r; i++){
            ans= ans*(N-r+i+1)/(i+1);
        } 
        return (int)ans;
    }
};