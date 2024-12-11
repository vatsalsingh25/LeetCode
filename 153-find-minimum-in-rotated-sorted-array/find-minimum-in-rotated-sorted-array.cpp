class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if (nums[low] <= nums[high]) {
                mini = min(mini, nums[low]);
                break;
            }

            if(nums[low]<=nums[mid]){
                mini = min(mini, nums[low]);
                low = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
// int findMin(vector<int>& nums) {
//     int n = nums.size();
//     int low = 0;
//     int high = n - 1;

//     // Initial assumption of minimum
//     int mini = nums[0];

//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         // If the array from low to high is sorted, return nums[low]
//         if (nums[low] <= nums[high]) {
//             mini = min(mini, nums[low]);
//             break;
//         }

//         // Check if the left part is sorted
//         if (nums[low] <= nums[mid]) {
//             mini = min(mini, nums[low]);
//             low = mid + 1;
//         } else {
//             // Right part must contain the minimum
//             mini = min(mini, nums[mid]);
//             high = mid - 1;
//         }
//     }

//     return mini;
// }

};