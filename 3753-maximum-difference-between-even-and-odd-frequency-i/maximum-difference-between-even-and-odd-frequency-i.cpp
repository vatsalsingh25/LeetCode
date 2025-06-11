class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>hash;
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }
        int maxiOdd = INT_MIN;
        int miniEven=INT_MAX;
        for(auto it: hash){
            if(it.second%2==0){
                miniEven = min(miniEven, it.second);
            }
            else{
                maxiOdd = max(maxiOdd, it.second);
            }
        }
        return maxiOdd-miniEven;
    }
};