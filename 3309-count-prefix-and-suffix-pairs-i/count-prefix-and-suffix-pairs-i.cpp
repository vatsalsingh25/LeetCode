class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1>n2) return false;
        for(int i=0; i<n1; i++){
            if( str1[i]!=str2[i] || str1[i]!=str2[n2-n1+i] ) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i],words[j])) count++;
            }
        }
        return count;
    }
};