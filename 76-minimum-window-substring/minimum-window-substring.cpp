class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>tHash;

        for(int i=0; i<t.size(); i++){
            tHash[t[i]]++;
        }

        int count = t.size();
        int l=0, r=0, mini=INT_MAX;
        pair<int,int>substring;

        while(r<s.size()){
            if(tHash[s[r]]-- > 0){
                count--;
            }

            while(count==0){
                if(r-l+1<mini){
                    mini = r-l+1;
                    substring = {l,r};
                }
                if(tHash[s[l]]++ == 0){
                    count++;
                } 
                l++;
            }
            r++;
        }
        if (mini == INT_MAX) return "";
        return s.substr(substring.first, mini);
    }
};