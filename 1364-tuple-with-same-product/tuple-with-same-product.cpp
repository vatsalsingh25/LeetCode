class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                hash[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto it: hash){
            if(it.second>1){
                int combo = it.second*(it.second-1)/2;
                ans+=combo*8;
            }
        }
        return ans;
    }
};