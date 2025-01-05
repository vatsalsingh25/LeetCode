class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int suffSum = 0;
        for(int i=n-1; i>=0; i--){
            suffSum = (suffSum + shifts[i])%26;
            s[i] = 'a' + (s[i]-'a'+suffSum)%26;
        }
        return s;
    }
};