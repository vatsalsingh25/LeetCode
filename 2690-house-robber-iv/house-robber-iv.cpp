class Solution {
public:
    int func(vector<int>& nums, int mid){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;

            if(func(nums,mid)>=k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};