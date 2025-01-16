class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int xor1 = 0;
        for(int i=0; i<nums1.size(); i++){
            xor1^=nums1[i];
        }
        int xor2 = 0;
        for(int i=0; i<nums2.size(); i++){
            xor2^=nums2[i];
        }
        if(nums1.size()%2==1 && nums2.size()%2==1) return xor1^xor2;
        else if(nums1.size()%2==1) return xor2;
        else if(nums2.size()%2==1) return xor1;
        else return 0;
        
    }
};
// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int xor1 = 0, xor2 = 0;

//         // Compute XOR of all elements in nums1 and nums2
//         for (int num : nums1) {
//             xor1 ^= num;
//         }
//         for (int num : nums2) {
//             xor2 ^= num;
//         }

//         // Determine the contribution based on the array sizes
//         int result = 0;
//         if (nums1.size() % 2 == 1) {
//             result ^= xor2;
//         }
//         if (nums2.size() % 2 == 1) {
//             result ^= xor1;
//         }

//         return result;
//     }
// };
