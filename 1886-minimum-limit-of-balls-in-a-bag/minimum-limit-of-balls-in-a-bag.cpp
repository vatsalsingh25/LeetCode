class Solution {
public:
    int splits(vector<int>& nums, int mid){
        int n = nums.size();
        int ops = 0;
        for(int i=0; i<n; i++){
            ops+=(nums[i]-1)/mid;
        }
        return ops;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(splits(nums,mid) > maxOperations) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};