class Solution {
public:
    bool isValid(string s){
        int n = s.size();
        if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') &&
           (s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u')) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size();
        int w = words.size();
        unordered_map<int,int>mpp;
        int cumSum = 0;
        for(int i=0; i<w; i++){
            if(isValid(words[i])){
                cumSum++;
                mpp[i]=cumSum;
            }
            else mpp[i]=cumSum;
        }
        vector<int>ans;
        for(int i=0; i<q; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if (start==0) ans.push_back(mpp[end]);
            else ans.push_back(mpp[end]-mpp[start-1]);
        }
        return ans;
    }
};