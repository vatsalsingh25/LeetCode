class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string,int>hash;
        for(int i=0; i<k; i++){
            string ss = "";
            for(int j=n/k*i; j<n/k*i+n/k; j++){
                ss+=s[j];
            }
            hash[ss]++;
        }
        for(int i=0; i<k; i++){
            string ss = "";
            for(int j=n/k*i; j<n/k*i+n/k; j++){
                ss+=t[j];
            }
            if(hash.find(ss)!=hash.end() && hash[ss]!=0) hash[ss]--;
            else return false;
        }
        return true;
    }
};