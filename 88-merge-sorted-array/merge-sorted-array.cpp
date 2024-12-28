class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=m-1;
        int i2=n-1;
        int insertInd = n+m-1;
        while(i1>=0 && i2>=0){
            if(nums1[i1]<=nums2[i2]){
                nums1[insertInd]=nums2[i2];
                insertInd--;
                i2--;
            }
            else{
                nums1[insertInd]=nums1[i1];
                insertInd--;
                i1--;                
            }
        }
        while (i2 >= 0) {
            nums1[insertInd] = nums2[i2];
            i2--;
            insertInd--;
        }
    }
};