class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>tHash;
        unordered_map<char,int>windowHash;

        for(int i=0; i<t.size(); i++){
            tHash[t[i]]++;
        }

        int have=0, need=tHash.size();
        int l=0, r=0, mini=INT_MAX;
        pair<int,int>substring;

        while(r<s.size()){
            if(tHash.find(s[r])!=tHash.end()){
                windowHash[s[r]]++;
                if(windowHash[s[r]]==tHash[s[r]]) have++;
            }

            while(have>=need){
                if(r-l+1<mini){
                    mini = r-l+1;
                    substring = {l,r};
                }
                if(tHash.find(s[l])!=tHash.end()){
                    windowHash[s[l]]--;
                    if(windowHash[s[l]]<tHash[s[l]]) have--;
                } 
                l++;
            }
            r++;
        }
        if (mini == INT_MAX) return "";
        return s.substr(substring.first, mini);
    }
};