class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(minDiff>abs(sum-target)){
                        minDiff = abs(sum-target);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};