class Solution {
public:
    int binarySearch(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int h = n-1;

        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]>=k) h = mid-1;
            else l = mid+1;
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = n-binarySearch(nums, 1);
        int neg = binarySearch(nums,0);
        return max(pos,neg);
    }
};