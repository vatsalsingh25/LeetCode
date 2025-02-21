class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(),nums.end());
        int count = 0;
        while(minHeap.top()<k){
            long mini = minHeap.top();
            minHeap.pop();
            long maxi = minHeap.top();
            minHeap.pop();
            long term = 2L*mini+maxi;
            minHeap.push(term);
            count++;
        }
        return count;
    }
};