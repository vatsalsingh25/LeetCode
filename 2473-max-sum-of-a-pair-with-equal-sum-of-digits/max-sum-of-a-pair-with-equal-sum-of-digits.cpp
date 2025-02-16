class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>hash;
        for(int i=0; i<n; i++){
            hash[digitSum(nums[i])].push_back(nums[i]);
        }
        int maxi = INT_MIN;
        for(auto it: hash){
            if(it.second.size()>1){
                sort(it.second.begin(), it.second.end(), greater<int>());
                int sum = it.second[0] + it.second[1];
                maxi = max(maxi, sum);
            }
        }
        if(maxi==INT_MIN) return -1;
        return maxi;
    }
};