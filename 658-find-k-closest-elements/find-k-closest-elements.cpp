class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int mini = INT_MAX;
        int miniInd = 0;
        for(int i=0; i<arr.size(); i++){
            if(abs(x-arr[i])<mini){
                mini = abs(x-arr[i]);
                miniInd = i;
            } 
        }
        minHeap.push(arr[miniInd]);
        int left = miniInd-1;
        int right = miniInd+1;
        while(k-1){
            int leftDist = INT_MAX;
            int rightDist = INT_MAX;
            if(left>=0){
                leftDist = abs(arr[left]-x);
            }
            if(right<arr.size()){
                rightDist = abs(arr[right]-x);
            }
            if(leftDist<=rightDist){
                minHeap.push(arr[left]);
                left--;
                k--;
            }
            else{
                minHeap.push(arr[right]);
                right++;
                k--;
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};