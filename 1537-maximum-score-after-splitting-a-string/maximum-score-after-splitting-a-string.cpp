class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0;
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        if (zero==n || one==n) return n-1;
        int currZero = 0, leftZero = zero;
        int currOne = 0, leftOne = one;
        int sum = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0') currZero++;
            else leftOne--;
            sum = max(sum, currZero+leftOne);
        }
        return sum;
    }
};