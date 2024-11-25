class Solution {
public:
    int minForWindowSize(vector<int>& nums, int k){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        int left = 0;
        int right = k-1;
        int mini = INT_MAX;
        while(right<n){
            if(sum>0) mini = min(sum,mini);
            if(right+1<n) sum = sum+nums[right+1]-nums[left];
            right++;
            left++;
        }
        return mini;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i=l; i<=r; i++){
            ans = min(ans, minForWindowSize(nums,i));
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};