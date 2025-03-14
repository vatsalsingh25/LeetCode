class Solution {
public:
    long long func(vector<int>& candies, long long candiesEach){
        int n = candies.size();
        long long count = 0;
        for(int i=0; i<n; i++){
            count+= (candies[i])/candiesEach;
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(low<=high){
            long long mid = (low+high)/2;

            if(func(candies,mid)>=k){
                ans = mid;
                low = mid+1;
            }   
            else high = mid-1;
        }
        return ans;
    }
};