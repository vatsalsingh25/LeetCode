class Solution {
public:
    int maxDifference(string s) {
        vector<int>hash(26,0);
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']++;
        }
        sort(hash.begin(), hash.end());
        int evenFreq = 0;
        for(int i=0; i<26; i++){
            if(hash[i]!=0 && hash[i]%2==0){
            evenFreq = hash[i];
                break;
            }
        }
        int oddFreq = 0;
        for(int i=25; i>=0; i--){
            if(hash[i]!=0 && hash[i]%2==1){
            oddFreq = hash[i];
                break;
            }
        }
        return oddFreq-evenFreq;
    }
};