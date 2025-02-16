class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        for(int i=0; i+k<=n; i++){
            if( count(s.begin()+i, s.begin()+i+k, s[i]) == k ){
                bool left = (i==0) || s[i-1]!=s[i];
                bool right = (i==n-1) || s[i]!=s[i+k];
                if(left && right) return true;                
            }
        }
        return false;
    }
};