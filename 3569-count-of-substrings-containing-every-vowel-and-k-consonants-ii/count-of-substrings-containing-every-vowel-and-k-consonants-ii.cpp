class Solution {
public:
    long long function(string&word, int k){
        int n = word.size();
        int l=0;
        int r=0;
        unordered_map<char,int>hash;
        long long count = 0;
        while(r<n){       

            if(word[r]=='a' || word[r]=='e' || word[r]=='i' || word[r]=='o' || word[r]=='u') hash[word[r]]++;
            else hash['x']++;
    
            while(hash['a']>=1 && hash['e']>=1 && hash['i']>=1 && hash['o']>=1 && hash['u']>=1 && hash['x']>=k){
                count+=1+((n-1)-r);
                if(word[l]=='a' || word[l]=='e' || word[l]=='i' || word[l]=='o' || word[l]=='u') hash[word[l]]--;
                else hash['x']--;
                l++;
            } 
            r++;
        }
        return count;
    }

    long long countOfSubstrings(string word, int k) {
        return function(word,k)-function(word,k+1);
    }
};

