class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int fluctuation = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) fluctuation++;
        }
        if(nums[n-1]>nums[0]) fluctuation++;

        if(fluctuation == 1 || fluctuation == 0) return true;
        return false;
    }
};