class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>hash;
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        int alreadySorted = true;
        for(auto it: hash){
            if(it.second>1){
                alreadySorted = false;
                break;
            }
        }
        if(alreadySorted) return 0;

        int count = 0;
        int i=0;
        while(true){
            count++;
            bool outOfBoundFlag = false;
            for(int j=i; j<i+3; j++){
                if(j<n) hash[nums[j]]--;
                else{
                    outOfBoundFlag = true;
                    break;
                } 
            }
            if (outOfBoundFlag) break;
            bool duplicateFlag = false;
            for(auto it: hash){
                if(it.second>1){
                    duplicateFlag = true;
                    break;
                }
            }
            if(duplicateFlag){
                i+=3;
                continue;
            } 
            else break;
            
        }
        return count;
    }
};