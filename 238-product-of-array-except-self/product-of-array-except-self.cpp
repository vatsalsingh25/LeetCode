class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>sufix(n);

        int sufMul = 1;
        int preMul = 1;

        for(int i=0; i<n; i++){
            prefix[i]=preMul;
            preMul = nums[i]*preMul;            
        }
        for(int i=n-1; i>=0; i--){
            sufix[i]=sufMul;
            sufMul = nums[i]*sufMul;            
        }

        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=prefix[i]*sufix[i];
        }
        return ans;
    }
    // [1,2,3,4]

    // [1,1,2,6]
    // [24,12,4,1]

    // [24,12,8,6]
};