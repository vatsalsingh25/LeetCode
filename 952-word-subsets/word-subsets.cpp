class Solution {
public:
    bool isUniversal(string a, unordered_map<char,int>mppW2){
        unordered_map<char, int> wordFreq;
        for (char ch : a) {
            wordFreq[ch]++;
        }
        for (const auto& [ch, freq] : mppW2) {
            if (wordFreq[ch] < freq) {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mppW2;
        for(int i=0; i<words2.size(); i++){
            unordered_map<char,int>temp;
            for(int j=0; j<words2[i].size(); j++){
                temp[words2[i][j]]++;
            }
            for(auto it: temp){
                if(mppW2.find(it.first)==mppW2.end()) mppW2[it.first]=it.second;
                else mppW2[it.first]=max(it.second, mppW2[it.first]);
            }
        }
        vector<string> ans;
        for(int i=0; i<words1.size(); i++){
            if(isUniversal(words1[i],mppW2)) ans.push_back(words1[i]); 
        }
        return ans;
    }
};