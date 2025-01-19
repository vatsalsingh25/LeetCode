class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for(int i=0; i<derived.size(); i++){
            xorr =  xorr ^ derived[i];
        }
        if(xorr==0) return true;
        return false;
    }
};