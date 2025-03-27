class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int,int>freq;
        int dominant = 0;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for(auto it: freq){
            if(it.second>n/2) dominant = it.first;
        }
        if(dominant==0) return -1;

        int count = freq[dominant];
        
        int countDomL = 0;
        int countDomR = count;

        for(int i=0; i<n-1; i++){
            if(nums[i]==dominant){
                countDomL++;
                countDomR--;
            }
            int arrHalfL = (i+1)/2;
            int arrHalfR = (n-i-1)/2;
            if(countDomL>arrHalfL && countDomR>arrHalfR) return i;
        }
        return -1;
        
    }
};