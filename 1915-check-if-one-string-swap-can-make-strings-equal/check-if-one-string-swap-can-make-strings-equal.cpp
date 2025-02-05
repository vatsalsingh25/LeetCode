class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1!=n2) return false;

        vector<int>swappedInd;
        int count = 0;  //difference counter
        for(int i=0; i<n1; i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count>2) return false;
                swappedInd.push_back(i);
            }
        }

        if(count == 0) return true;
        if(count == 1) return false;

        //count = 2;
        if(s1[swappedInd[0]]==s2[swappedInd[1]] && 
           s1[swappedInd[1]]==s2[swappedInd[0]]) return true;
        
        return false;
    }
};