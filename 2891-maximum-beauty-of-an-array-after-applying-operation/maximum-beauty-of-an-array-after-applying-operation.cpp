class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r<n){
            while(nums[r]-nums[l]>2*k) l++;
            r++;
            maxi = max(maxi, r-l);
        }
        return maxi;



        // int maxi = 0;
        // for(int i=0; i<n; i++){
        //     int count=1;
        //     for(int j=i+1; j<n; j++){
        //         if((nums[j]-nums[i])>2*k) break;
        //         else count++;
        //     }
        //     maxi = max(maxi, count);
        // }
        // return maxi;
    }
};