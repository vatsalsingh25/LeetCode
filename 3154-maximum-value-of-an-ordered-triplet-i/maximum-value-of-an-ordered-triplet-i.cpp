class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = LONG_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long current = (1LL*(nums[i]-nums[j])*nums[k]);
                    maxi = max(maxi, current);
                }
            }
        }
        if(maxi<0) return 0;
        return maxi;
    }
};