class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        int days = n/4;
        int even = days/2;
        int odd = days-even;

        sort(pizzas.begin(), pizzas.end(), greater<int>());
        long long ans = 0;
        for(int i=0; i<odd; i++){
            ans+=pizzas[i];
        }
        int i=odd+1;
        while(even--){
            ans+=pizzas[i];
            i+=2;
        }
        return ans;
    }
};