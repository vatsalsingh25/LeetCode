class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(n==0) return true;
        int l = flowerbed.size();

        if(l==1){
            if(flowerbed[0]==0 && n==1) return true;
            else return false;
        }

        for(int i=0; i<l; i++){
            if(flowerbed[i]==1) continue;
            else{
                if(i==0 && flowerbed[i+1]==0){
                    flowerbed[i]++;
                    n--;
                    if(n==0) return true;
                    continue;
                }
                if(i!=0 && i!=l-1){
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                        flowerbed[i]++;
                        n--;
                        if(n==0) return true;
                    }
                    else continue;
                }
                if(i==l-1 && flowerbed[i-1]==0){
                    flowerbed[i]++;
                    n--;
                    if(n==0) return true;
                    continue;
                }
            }
        }
        return false;
    }
};