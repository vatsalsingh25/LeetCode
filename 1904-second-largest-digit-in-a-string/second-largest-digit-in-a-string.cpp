class Solution {
public:
    int secondHighest(string s) {
        int n = s.size();

        int largest = INT_MIN;
        int slargest = INT_MIN;

        for(int i=0; i<n; i++){
            if(s[i]-'0'<0 || s[i]-'0'>9) continue;
            if(s[i]-'0'>largest){
                slargest = largest;
                largest = s[i]-'0';
                continue;
            }
            if(s[i]-'0'>slargest && s[i]-'0'!=largest) slargest = s[i]-'0';
        }

        if(slargest==INT_MIN) return -1;
        return slargest;
    }
};