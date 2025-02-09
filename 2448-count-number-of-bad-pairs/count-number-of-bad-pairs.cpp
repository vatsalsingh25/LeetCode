class Solution {
public:
    long long factorial(int n){
        if(n==0) return 1;
        return n*factorial(n-1);
    }
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();

        long long totalPairs = (long long)n*(n-1)/2;
        unordered_map<int,int>hash;

        for(int i=0; i<n; i++){
            hash[nums[i]-i]++;
        }

        long long goodPairs = 0;
        for(auto it: hash){
            if(it.second>1) goodPairs+=(long long)(it.second)*(it.second-1)/2;
        }

        return totalPairs-goodPairs;
    }
};