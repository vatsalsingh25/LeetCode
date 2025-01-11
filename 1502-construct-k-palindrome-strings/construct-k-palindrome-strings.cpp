class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char,int>freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        int oddCount = 0;
        for(auto it: freq){
            if(it.second%2==1) oddCount+=1;
        }
        if(oddCount>k) return false;
        return true;
    }
};