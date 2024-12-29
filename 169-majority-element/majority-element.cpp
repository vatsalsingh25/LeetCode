class Solution {
public:
    int majorityElement(vector<int>& nums){
        int n = nums.size();
        int majorEle;
        int count = 0;
        for(int i=0; i<n; i++){
            if(count==0){
                majorEle = nums[i];
                count++;
            } 
            else if(nums[i]==majorEle) count++;
            else count--;
        }
        return majorEle;
    }
};