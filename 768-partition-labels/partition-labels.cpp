class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastOccurence;
        int n = s.size();
        for(int i=0; i<n; i++){
            lastOccurence[s[i]] = i;
        }

        vector<int>ans;
        int lastOccurInd = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            if(lastOccurence[s[i]] > lastOccurInd){
                lastOccurInd = lastOccurence[s[i]]; 
            }

            if(lastOccurInd == i){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }

        return ans;
    }
};