class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = s.size(), n2 = goal.size();
        if(n1!=n2) return false;

        vector<int>swappedInd;
        int count = 0;  //difference counter
        for(int i=0; i<n1; i++){
            if(s[i]!=goal[i]){
                count++;
                if(count>2) return false;
                swappedInd.push_back(i);
            }
        }

        if(count == 0){
            vector<int>hash(26,0);
            for(int i=0; i<s.size(); i++){
                if(hash[s[i]-'a']!=0) return true;
                else hash[s[i]-'a']++;
            }
            return false;
        }

        if(count == 1 ) return false;

        //count = 2;
        if(s[swappedInd[0]]==goal[swappedInd[1]] && 
           s[swappedInd[1]]==goal[swappedInd[0]]) return true;
        
        return false;
    }
};