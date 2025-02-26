class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++){
            int first = nums[i];
            int second = i+1, third = n-1;
            while(second<third){
                int sum = first+nums[second]+nums[third];
                if(closest>abs(target-sum)){
                    closest = abs(target-sum);
                    ans = sum;
                }
                if(target-sum>0) second++;
                else third--;
            }
        }
        return ans;
    }
};