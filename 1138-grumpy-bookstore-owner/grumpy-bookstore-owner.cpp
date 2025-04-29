class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res=0;
        int maxi=0;
        int extra=0;
        int l=0;
        int r=minutes-1; 
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i]==0){
                res+=customers[i];
            }
        }
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1){
                extra+= customers[i];
            }
        }
        maxi =extra;

        while(r<customers.size()-1){
            r++;
            if(grumpy[r]==1){
                extra+= customers[r];
            }
            if(grumpy[l]==1){
                extra-= customers[l];
            }
            l++;
             maxi = max(extra, maxi);
        }

        return res +maxi;
    }
};