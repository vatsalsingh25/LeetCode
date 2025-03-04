class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        //using two pointer
        int indLess = 0;
        int indMore = nums.size()-1;
        vector<int>ans(nums.size(),1e7);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                ans[indLess]=nums[i];
                indLess++;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]>pivot){
                ans[indMore]=nums[i];
                indMore--;
            }           
        }
        for(int i=0; i<nums.size(); i++){
            if(ans[i]==1e7) ans[i]=pivot;
        }
        return ans;
    }
};