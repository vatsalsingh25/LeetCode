class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>diffArr(n+1,0);     //n+1 to accomodate the operation to the last index
        for(int i=0; i<shifts.size(); i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            //difference array method
            if(shifts[i][2]==1){
                diffArr[start]++;   //marks the `start` of increment range
                diffArr[end+1]--;   //marks the `end` of increment range
            }
            else{
                diffArr[start]--;   //marks the `start` of decrement range
                diffArr[end+1]++;   //marks the `end` of decrement range
            }
        }
        // prefix sum to calculate the net change
        int prefSum = 0;
        for(int i=0; i<n; i++){
            prefSum = (prefSum+diffArr[i])%26;  //wrap around if exceeds the alphabet range
            if(prefSum>=0) s[i] = 'a'+(s[i]-'a'+prefSum)%26;  // adjusting the values according to the pref sum
            else s[i] = 'a'+(s[i]-'a'+prefSum+26)%26; // if looping backwards, add 26 to get back in range
        }
        return s;
    }
};