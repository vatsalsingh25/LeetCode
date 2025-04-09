class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int>hash;
        for(int i=n-1; i>=0; i--){
            if(hash[nums[i]]>=1){
                if((i+1)%3==0) return (i+1)/3;
                else return ((i+1)/3)+1; 
            }
            else hash[nums[i]]++;
        }
        return 0;
    }
};