class Solution {
public:
    string functionForRLE(string  &s){
        string temp = "";
        int count = 0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(s[start]==s[i]) count++;
            else{
                temp+=to_string(count);
                temp+=s[start];
                count = 1;
                start = i;
            }
        }
        temp+=to_string(count);
        temp+=s[s.size()-1];
        return temp;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i=1; i<n; i++){
            if(n==1) return s;
            s=functionForRLE(s);
        }
        return s;
    }
};