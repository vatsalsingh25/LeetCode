class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int smallest = INT_MAX;
        int profit = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(prices[i]<smallest) smallest = prices[i];
            profit = prices[i]-smallest;
            maxi = max(maxi,profit);
        }
        return maxi;
    }
};