class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int curr = 0;
        int maxi = INT_MIN;
        while(r<n){
            while( (curr & nums[r]) != 0){
                curr = curr ^ nums[l];
                l++;
            }
            curr = curr | nums[r];
            maxi = max(maxi, r-l+1);
            r++;
        }   
        return maxi;
    }
};