class Solution {
public:
    long long func(vector<int>& ranks, long long mid){
        long long time = 0;
        for(int i=0; i<ranks.size(); i++){
            time+=sqrt(mid/ranks[i]);
        }
        return time;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long lowestRank = *max_element(ranks.begin(), ranks.end());
        long long high = 1LL * lowestRank * cars * cars;

        long long ans = 0;
        while(low<=high){
            long long mid = (low+high)/2;

            if(func(ranks, mid)<cars) low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};