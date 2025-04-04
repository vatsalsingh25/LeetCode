class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxProduct = 0, maxI = 0, maxDiff = 0;
        for(int k=0; k<n; k++){
            maxProduct = max(maxProduct, maxDiff*nums[k]);
            maxDiff = max(maxDiff, maxI-nums[k]);
            maxI = max(maxI, (1LL)*nums[k]);
        }   
        return maxProduct;
    }
};