class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int count = 0;
        unordered_map<string,int>hash;
        unordered_map<string,int>hashSimilar;
        for(int i=0; i<n; i++){
            string s = words[i];

            if(s[0]==s[1]){
                hashSimilar[s]++;
                continue;
            }

            string rev = "";
            rev+=s[1];
            rev+=s[0];

            if(hash.find(rev)!=hash.end()){
                count+=4;
                hash[rev]--;
                if(hash[rev]==0) hash.erase(rev);
            }
            else hash[s]++;
        }
        bool middle = false;
        for(auto it: hashSimilar){
            count+=(it.second/2)*4;
            if(it.second%2==1 && middle==false){
                count+=2;
                middle = true;
            }
        }
        return count;
    }
};