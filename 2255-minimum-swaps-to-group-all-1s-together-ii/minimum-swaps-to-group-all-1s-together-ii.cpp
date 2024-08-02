class Solution {
public:
    int minSwaps(vector<int>& nums) {

        vector<int>nums2(nums.begin(),nums.end());
        nums2.insert(nums2.end(),nums.begin(),nums.end()); //.insert(postition,starting,ending)

        int oneCount = count(nums.begin(),nums.end(),1); 
        if(oneCount==0) return 0;                         //edge case
        int mini = INT_MAX;

        int l=0;
        int r=oneCount-1;
        int zeroCount = count(nums2.begin()+l,nums2.begin()+r+1,0);
        if(zeroCount==0) return 0;
        while(r<nums2.size()-1){
            if(nums2[l]==0) zeroCount--;
            l++;
            r++; 
            if(nums2[r]==0) zeroCount++;            
            if(zeroCount==0) return 0;
            mini = min(mini,zeroCount);          
        }
        return mini;  
    }
};


