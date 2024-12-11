// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int bad = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(!isBadVersion(mid)){
                low=mid+1;
            }
            else{
                bad = mid;
                high = mid-1;
            }
        }
        return bad;
    }
};