class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>hash;

        int maxi = INT_MIN;

        int l=0, r=0;
        while(r<fruits.size()){
            hash[fruits[r]]++;
            while(hash.size()>2){
                hash[fruits[l]]--;
                if(hash[fruits[l]]==0) hash.erase(fruits[l]);
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};


