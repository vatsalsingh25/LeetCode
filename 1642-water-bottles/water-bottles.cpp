class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int k = numExchange;
        int ans = numBottles;
        while(n/k>0){
            ans+=n/k;
            n = n/k+n%k;
        }
        return ans;
    }
};
