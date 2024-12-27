class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), left=0, mid=0, right = n-1;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[mid],nums[left]);
                mid++;
                left++;
            }
            else if(nums[mid]==2){
                swap(nums[right],nums[mid]);
                right--;
            }
            else mid++;
        }
    }
};