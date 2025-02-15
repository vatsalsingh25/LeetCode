class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            bool left = true;
            if(i-k>=0){
                if(nums[i-k]>=nums[i]) left = false;
            }
            bool right = true;
            if(i+k<=n-1){
                if(nums[i+k]>=nums[i]) right = false;
            }
            if(left && right) sum+=nums[i];
        }       
        return sum;
    }
};