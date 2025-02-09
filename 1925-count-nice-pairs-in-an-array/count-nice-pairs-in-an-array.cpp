class Solution {
public:
    int MOD = 1e9+7;
    int rev(int num){
        int revNum = 0;
        while(num>0){
            int last = num%10;
            num/=10;
            revNum=revNum*10+last;
        }
        return revNum;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>hash;
        long long goodPairs = 0;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]-rev(nums[i])]++;
        }

        for(auto it: hash){
            if(it.second>1) goodPairs = (goodPairs + ((long long)it.second * (it.second - 1) / 2) % MOD) % MOD;
        }

        return goodPairs%MOD;
    }
};