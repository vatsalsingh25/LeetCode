class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int>freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        int count = 0;
        for(auto it: freq){
            if(it.second%2==1) count+=1;
            else count+=2; 
        }
        return count;
    }
};