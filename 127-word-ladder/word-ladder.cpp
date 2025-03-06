class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        for(int i=0; i<wordList.size(); i++){
            st.insert(wordList[i]);
        }
        while(!q.empty()){
            string s = q.front().first;
            int num = q.front().second;
            q.pop();

            for(int i=0; i<s.size(); i++){
                for(int j=0; j<26; j++){  
                    string temp = s;  
                    temp[i]='a'+j;
                    if(st.find(temp)!=st.end()){
                        if(temp==endWord) return num+1;
                        q.push({temp,num+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;

    }
};