class Solution {
public:
    string clearDigits(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) count++;
        }
        int i=0;
        while(count){
            if(isdigit(s[i])){
                s.erase(s.begin()+i-1,s.begin()+i+1);
                i=max(0,i-2);
                count--;
            }
            else i++;
        }
        return s;
    }
};