class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while(right - left >= k )
            if(x - arr[left] > arr[right] - x)
                left++;
            else
                right--;
        return vector<int> (arr.begin()+left, arr.begin()+left+k);       
    }
};