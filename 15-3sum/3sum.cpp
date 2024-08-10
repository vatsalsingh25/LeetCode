class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int target = 0;
        for(int i=0; i<=n-3; i++){
            target = 0 - nums[i];
            int sum = 0;
            int l = i+1;
            int r = n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(l<r){
                sum = nums[l]+nums[r];
                if(sum==target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(nums[l]==nums[l-1] && l<r) l++;
                    while(nums[r]==nums[r+1] && l<r) r--;
                }
                else if(sum>target) r--;
                else l++;                
            }
        }
        return ans;
    }
    // 0 0 0 0
    // 1 2 3 4


}; 