class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;
        for(int i=n-1; i>=1; i--){
            if(nums[i-1]<nums[i]){
                breakPoint = i-1;
                break;
            }
        }
        if(breakPoint == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int smallestGreater=breakPoint+1;
        for(int i= breakPoint; i<n; i++){
            if(nums[i]<=nums[smallestGreater] && nums[i]>nums[breakPoint]) smallestGreater=i;
        }
        swap(nums[breakPoint],nums[smallestGreater]);
        sort(nums.begin()+breakPoint+1, nums.end());
    }
};