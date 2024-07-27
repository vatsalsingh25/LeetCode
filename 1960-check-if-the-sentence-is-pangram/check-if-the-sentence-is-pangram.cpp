class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26) return false;
        vector<int>hash(26,0);
        for(int i=0; i<sentence.size(); i++){
            hash[sentence[i]-'a']++;
        }
        for(int i=0; i<=25; i++){
            if(hash[i]==0) return false;
        }
        return true;
    }
};