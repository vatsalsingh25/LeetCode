class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        for(int i=0; i<n; i++){
            string s= words[i];
            for(int j=0; j<n; j++){
                if(i!=j){
                    if( words[j].find(s)!=string::npos ){
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};