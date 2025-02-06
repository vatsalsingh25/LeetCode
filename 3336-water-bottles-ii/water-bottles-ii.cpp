class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int k = numExchange;
        int full = numBottles;
        int empty = 0;
        int ans = 0;

        while(1){
            if(full>0 && empty<k){
                empty+=full;
                ans+=full;
                full=0;
            }
            else if(empty>=k){
                full++;
                empty-=k;
                k++;
            }
            else break;
        }
        return ans;
    }
};