class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        for(auto it: hash){
            if(it.second%2==1) return false;
        }
        return true;
    }
};