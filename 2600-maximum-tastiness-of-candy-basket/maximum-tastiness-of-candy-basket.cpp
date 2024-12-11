class Solution {
public:
    int countBasket(vector<int>&price, int mid){
        int basket = 1;
        int curr = 0;
        for(int i=1; i<price.size(); i++){
            if((price[i]-price[curr])>=mid){
                curr = i;
                basket++;
            }
        }
        return basket;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int low = 1;
        int high = price[n-1]-price[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(countBasket(price,mid)>=k) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};