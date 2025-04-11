class Solution {
public:
    bool isSymmetric(int n){
        string s = to_string(n);
        if(s.size()%2==1) return false;
        int half = s.size()/2;
        int sumLeft=0, sumRight=0;
        for(int i=0; i<half; i++){
            sumLeft += s[i]-'0';
        }
        for(int i=half; i<s.size(); i++){
            sumRight += s[i]-'0';
        }
        return sumLeft == sumRight;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if(isSymmetric(i)) count++;
        }
        return count;
    }
};