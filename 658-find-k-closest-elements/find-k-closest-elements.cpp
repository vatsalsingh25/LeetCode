class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        for(int i=0; i<arr.size(); i++){
            int diff = abs(arr[i]-x);
            minHeap.push({diff,arr[i]});
        }
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};