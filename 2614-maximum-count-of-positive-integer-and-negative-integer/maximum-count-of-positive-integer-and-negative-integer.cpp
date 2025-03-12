class Solution {
public:
    int binarySearch(vector<int>& nums, int k){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = n-binarySearch(nums, 1);
        int neg = binarySearch(nums,0);
        return max(pos,neg);
    }
};