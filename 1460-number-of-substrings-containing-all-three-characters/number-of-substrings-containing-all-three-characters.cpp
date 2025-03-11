class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(); 
        unordered_map<char,int>hash;
        hash['a']=hash['b']=hash['c']=0;
        int l=0, r=0; 
        int count = 0;
        while(r<n){
            hash[s[r]]++;
            while(hash['a']>0 && hash['b']>0 && hash['c']>0){
                count+=1+((n-1)-r);
                hash[s[l]]--;
                l++;
            }
            r++;
        }

        return count;
    }
};