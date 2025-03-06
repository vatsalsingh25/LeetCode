class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());

        while(!q.empty()){
            string s = q.front().first;
            int num = q.front().second;
            q.pop();
            if(s==endWord) return num;
            for(int i=0; i<s.size(); i++){
                for(char j='a'; j<='z'; j++){  
                    string temp = s;  
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        
                        q.push({temp,num+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;

    }
};