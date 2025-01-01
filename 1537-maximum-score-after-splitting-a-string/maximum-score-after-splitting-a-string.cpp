class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') one++;
        }
        int currZero = 0;
        int remOne = one;
        int sum = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0') currZero++;
            else remOne--;
            sum = max(sum, currZero+remOne);
        }
        return sum;
    }
};