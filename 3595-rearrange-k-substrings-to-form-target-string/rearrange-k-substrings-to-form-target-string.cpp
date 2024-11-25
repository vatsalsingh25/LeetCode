class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string,int>hash;
        for(int i=0; i<n; i+=n/k){                      //loop k times in string s to get k subarrays
            string ss = s.substr(i,n/k);
            hash[ss]++;
        }
        for(int i=0; i<n; i+=n/k){                      //we will check each substring of t against hashmap of string s
            string ss = t.substr(i,n/k); 
            if(hash.find(ss)!=hash.end() && hash[ss]!=0) hash[ss]--;  // if found in hash, decrease count by one 
            else return false;                                        // if not, return false
        }
        return true;
    }
};