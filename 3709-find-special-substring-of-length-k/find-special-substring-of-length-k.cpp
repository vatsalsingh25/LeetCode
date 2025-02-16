class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        int l=0;
        int r=0;
        while(r<n){
            if(s[r]==s[l]){
                if(r-l+1==k){
                    bool left = (l==0) || s[l-1]!=s[l];
                    bool right = (r==n-1) || s[r]!=s[r+1];
                    if(left && right) return true;
                    l++;
                }
            }
            else{
               l=r; 
            }
            r++;
        }
        return false;
    }
};