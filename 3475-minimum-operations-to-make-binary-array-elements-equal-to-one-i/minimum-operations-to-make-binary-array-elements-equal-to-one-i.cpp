class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-2; i++){
            if(nums[i]==0){
                for(int j=i; j<i+3; j++){
                    nums[j] = nums[j]^1;
                }
                count++;
            }
        }
        if(nums[n-2]==0 || nums[n-1]==0) return -1;
        return count;
    }
};