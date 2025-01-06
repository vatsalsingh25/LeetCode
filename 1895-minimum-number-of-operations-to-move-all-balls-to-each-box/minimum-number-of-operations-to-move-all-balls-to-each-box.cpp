class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int>prefArr(n);
        int ballOnLeft = 0;
        int movesFromLeft = 0;
        for(int i=0; i<n; i++){
            movesFromLeft+=ballOnLeft;
            prefArr[i]=movesFromLeft;
            if(boxes[i]=='1') ballOnLeft++;
        }

        vector<int>suffArr(n);
        int ballOnRight = 0;
        int movesFromRight = 0;
        for(int i=n-1; i>=0; i--){
            movesFromRight+=ballOnRight;
            suffArr[i]=movesFromRight+prefArr[i];
            if(boxes[i]=='1') ballOnRight++;
        }

        return suffArr;
    }
};