class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>index;
        int n = nums.size();
        for(int i=0; i<n; i++){
            index[nums[i]].push_back(i);
        }
        
        int q = queries.size();
        vector<int>ans;
        for(int i=0; i<q; i++){
            vector<int>&arr=index[nums[queries[i]]];
            if(arr.size()==1){
                ans.push_back(-1);
                continue;
            } 
            int minDiff = INT_MAX;
            int ind = lower_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();//
            int m = arr.size();
            
            if(ind==0){
                int rightDist = min( arr[ind+1]-queries[i], n-(arr[ind+1]-queries[i]) );
                int leftDist = min( arr[m-1]-queries[i], n-(arr[m-1]-queries[i]) );
                minDiff = min(rightDist, leftDist);
            }
            else if(ind==m-1){
                int rightDist = min( queries[i]-arr[0], n-(queries[i]-arr[0]) );
                int leftDist = min( queries[i]-arr[ind-1], n-(queries[i]-arr[ind-1]) );
                minDiff = min(rightDist, leftDist);
            }
            else{
                int rightDist = min( arr[ind+1]-queries[i], n-(arr[ind+1]-queries[i]) );
                int leftDist = min( queries[i]-arr[ind-1], n-(queries[i]-arr[ind-1]) );
                minDiff = min(rightDist, leftDist);
            }
            ans.push_back(minDiff);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         unordered_map<int, vector<int>> index;
//         int n = nums.size();
        
//         for (int i = 0; i < n; i++) {
//             index[nums[i]].push_back(i);
//         }
        
//         int q = queries.size();
//         vector<int> ans;
        
//         for (int i = 0; i < q; i++) {
//             vector<int>& arr = index[nums[queries[i]]];
//             if (arr.size() == 1) {
//                 ans.push_back(-1);
//                 continue;
//             } 
            
//             int minDiff = INT_MAX;
//             int ind = lower_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();
//             int m = arr.size();
            
//             if (ind == 0) {
//                 int rightDist = min(arr[ind + 1] - queries[i], n - (arr[ind + 1] - queries[i]));
//                 int leftDist = min(arr[m - 1] - queries[i], n - (arr[m - 1]-queries[i]) );  
//                 minDiff = min(rightDist, leftDist);
//             }
//             else if (ind == m-1) {
//                 int rightDist = min(queries[i] - arr[0], n - (queries[i] - arr[0]));
//                 int leftDist = min(queries[i] - arr[ind - 1], n - (queries[i] - arr[ind - 1]));
//                 minDiff = min(rightDist, leftDist);
//             }
//             else {
//                 int rightDist = min(arr[ind+1] - queries[i], n - (arr[ind+1] - queries[i]));
//                 int leftDist = min(queries[i] - arr[ind - 1], n - (queries[i] - arr[ind - 1]));
//                 minDiff = min(rightDist, leftDist);
//             }
//             ans.push_back(minDiff);
//         }
//         return ans;
//     }
// };
