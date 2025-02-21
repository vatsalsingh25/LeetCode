class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap(nums.begin(),nums.end());
        int count = 0;
        while(minHeap.top()<k){
            minHeap.pop();
            count++;
        }
        return count;
    }
};