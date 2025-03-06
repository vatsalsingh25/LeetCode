class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>st;
        queue<pair<string,int>>q;
        q.push({startGene,0});
        for(int i=0; i<bank.size(); i++){
            st.insert(bank[i]);
        }
        vector<char>gene = {'A','C','G','T'};
        while(!q.empty()){
            string s = q.front().first;
            int num = q.front().second;
            q.pop();

            for(int i=0; i<s.size(); i++){
                for(int j=0; j<4; j++){  
                    string temp = s;  
                    temp[i]=gene[j];
                    if(st.find(temp)!=st.end()){
                        if(temp==endGene) return num+1;
                        q.push({temp,num+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return -1;        
    }
};