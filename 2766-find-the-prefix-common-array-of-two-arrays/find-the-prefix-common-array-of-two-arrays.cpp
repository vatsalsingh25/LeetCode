class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>mpA;
        unordered_map<int, int>mpB;
        vector<int>common;
        int preSum = 0;
        for(int i=0; i<A.size(); i++){
            if(A[i]==B[i]) preSum++;
            else{
                if(mpB.find(A[i])!=mpB.end() && mpB[A[i]]!=0){
                    mpB[A[i]]--;
                    preSum++;
                }
                else mpA[A[i]]++;

                if(mpA.find(B[i])!=mpA.end()){
                    mpA[B[i]]--;
                    preSum++;                   
                } 
                else mpB[B[i]]++;
            }
            common.push_back(preSum);
        }
        return common;
    }
};