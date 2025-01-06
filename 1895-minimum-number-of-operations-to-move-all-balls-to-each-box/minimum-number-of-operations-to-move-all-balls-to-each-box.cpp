class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>movesArr(n);
        for(int i=0; i<n; i++){
            int moves = 0;
            for(int j=0; j<n; j++){
                if(boxes[j]=='1') moves+=abs(i-j);
            }
            movesArr[i]=moves;
        }
        return movesArr;
    }
};