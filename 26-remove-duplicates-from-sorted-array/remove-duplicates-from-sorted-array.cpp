class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int place = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]!=nums[i]){
                nums[place+1]=nums[i];
                place++;
            }
        }
        return place+1;
    }
};