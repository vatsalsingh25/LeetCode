class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<string>st;
        unordered_set<char>st2;
        for(int i=0; i<n; i++){
            if(st2.find(s[i])==st2.end()){
                for(int j=n-1; j>=i+2; j--){
                    if( s[i]==s[j] && st2.find(s[i])==st2.end() ){
                        
                        for(int k=i+1; k<j; k++){
                            string ss = "";
                            ss+=s[i];
                            ss+=s[k];
                            ss+=s[j];
                            st.insert(ss);
                        }
                        break;
                    }
                }
            }
            st2.insert(s[i]);
        }

        return st.size();
    }
};