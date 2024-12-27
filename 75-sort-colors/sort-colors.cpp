class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int l = 0, r = 0;
        while(l<n && r<n){
            while(l<n && nums[l]==0){
                l++;
                r=l+1;
            } 
            if(r<n && nums[r]==0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
        l=n-1;
        r=n-1;
        while(l>=0 && r>=0){
            while(l>=0 && nums[l]==2){
                l--;
                r=l-1;
            } 
            if(r>=0 && nums[r]==2){
                swap(nums[l],nums[r]);
                l--;
            }
            r--;
        }
        return;
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 1) return; // No need to sort if there's only one or no element

//         // Step 1: Sort all 0s to the beginning
//         int l = 0, r = 0;
//         while (r < n) {
//             if (nums[r] == 0) {
//                 swap(nums[l], nums[r]);
//                 l++;
//             }
//             r++;
//         }

//         // Step 2: Sort all 2s to the end
//         l = n - 1;
//         r = n - 1;
//         while (r >= 0) {
//             if (nums[r] == 2) {
//                 swap(nums[l], nums[r]);
//                 l--;
//             }
//             r--;
//         }
//     }
// };
