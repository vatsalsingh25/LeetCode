class Solution {
public:
    bool isPalindrome(string p){
        int l=0;  
        int r=p.size()-1;
        while(l<r){
            if(p[l]!=p[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        string ss = "";
        string tt = "";
        int maxi = 1;
        for(int si=0; si<s.size(); si++){
            ss="";
            for(int sj=si; sj<s.size(); sj++){
                ss+=s[sj];
                if(isPalindrome(ss)) maxi = max(maxi, (int)ss.size());
                for(int ti=0; ti<t.size(); ti++){
                    tt="";
                    for(int tj=ti; tj<t.size(); tj++){
                        tt+=t[tj];
                        if(isPalindrome(tt)) maxi = max(maxi, (int)tt.size());
                        string test = ss+tt;
                        int size = test.size();
                        if(isPalindrome(test)){
                            maxi = max(maxi, size);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};