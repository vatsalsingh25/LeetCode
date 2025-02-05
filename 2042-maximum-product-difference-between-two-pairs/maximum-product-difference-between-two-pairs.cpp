class Solution {
public:    

    int maxProductDifference(vector<int>& nums) {

        int max = 0;
        int indMax;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=max){
                max=nums[i];
                indMax = i;
            }             
        }    
        int smax = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=smax && i!=indMax) smax=nums[i];                     
        }     
        int min = 10000;
        int indMin;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=min) {
                min=nums[i];
                indMin=i;
            }                     
        }       
        int smin = 10000;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=smin && i!=indMin) smin=nums[i];
        }
        return (max*smax)-(min*smin);
    }
};