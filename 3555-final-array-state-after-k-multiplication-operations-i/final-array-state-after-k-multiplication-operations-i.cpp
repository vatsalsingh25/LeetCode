class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; i++){
            int mini = nums[0];
            int ind = 0;
            for(int j=0; j<nums.size(); j++){
                if(mini>nums[j]){
                    mini = nums[j];
                    ind = j;
                } 
            }
            nums[ind]=multiplier*nums[ind];
        }
        return nums;
    }
};