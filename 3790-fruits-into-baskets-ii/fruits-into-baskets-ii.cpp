class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>occupied(n,0);
        for(int i=0; i<n; i++){
            int num = fruits[i];
            for(int j=0; j<n; j++){
                if(baskets[j]>=num && occupied[j]==0){
                    occupied[j]=1;
                    break;
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(occupied[i]==0) count++;
       }
        return count;        
    }
};