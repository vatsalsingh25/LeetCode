class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum<0) sum = 0;
            maxi = max(maxi,sum);
        }
        int mini = 0;
        sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum>0) sum = 0;
            mini = min(mini,sum); 
        }
        return max(abs(maxi),abs(mini));
    }
};