class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int maxiInc = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]>nums[i]){
                len++;
                maxiInc = max(maxiInc, len);
            }
            else{
                len=0;
            }
        }
        len = 0;
        int maxiDec = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]<nums[i]){
                len++;
                maxiDec = max(maxiDec, len);
            } 
            else{
                len=0;
            }
        }

        return max(maxiInc, maxiDec)+1;
    }
};