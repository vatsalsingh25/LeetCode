class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int curr = 0;
        int maxi = INT_MIN;
        while(r<n){
            while( (curr & nums[r]) != 0){
                curr = curr ^ nums[l];
                l++;
            }
            curr = curr | nums[r];
            maxi = max(maxi, r-l+1);
            r++;
        }   
        return maxi;
    }
};
// the main logic behind this problem is,
// how can we know that each and every number satissfy the & condition with the new number so that we can add it in sliding window
// what we can do is carry forward all the set bits
//eg 1->00000001 curr = 00000001
//   3->00000011 now we seee that curr & 3 is not 0, hence we shrink window and unset 1 and curr becomes 00000010
//   8->00001000 curr & 8 = 0, valid hence we set curr = 00001011 so that we can check ahead
//  48->00101010 curr & 48 = 0, valid hence we set curr = 00101011, simnultaneously we also update maximum length
//  10->00000110 curr & 10 != 0, shrink until valid and unset curr values simulaneously as yo shrink
// now if we encounted   