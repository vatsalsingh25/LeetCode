class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        long long int currSum = 0;
        int count = 0;
        for(int i=0; i<n-1; i++){
            currSum+=nums[i];
            long long int rem = sum-currSum;
            if(currSum>=rem) count++;
        }
        return count;
    }
};