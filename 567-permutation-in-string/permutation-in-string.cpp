class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size()) return false;

        unordered_map<char,int>mapS1;
        for(int i=0; i<s1.size(); i++){
            mapS1[s1[i]]++;
        }
        int l=0, r=s1.size();
        unordered_map<char,int>mapS2;

        for(int i=0; i<s1.size(); i++){
            mapS2[s2[i]]++;
        }
        if(mapS1==mapS2) return true;
        while(r<s2.size()){
            mapS2[s2[r]]++;
            r++;
            mapS2[s2[l]]--;
            if (mapS2[s2[l]] == 0) mapS2.erase(s2[l]);
            l++;
            if(mapS1==mapS2) return true;
        }
        return false;
    }
};