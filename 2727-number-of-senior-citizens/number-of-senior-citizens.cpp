class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;

        for(int i=0; i<details.size(); i++){
            if((10*(details[i][11]-'0')+(details[i][12]-'0'))>60) count++;
        }
        return count;
    }
};