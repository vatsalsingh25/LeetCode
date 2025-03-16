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
            int ind = lower_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();
            int m = arr.size();
            int right = (ind + 1) % m;
            int left = (ind - 1 + m) % m;
            int rightDist = min( abs(arr[right]-queries[i]), n-abs(arr[right]-queries[i]) );
            int leftDist = min( abs(queries[i]-arr[left]), n-abs(queries[i]-arr[left]) );
            minDiff = min(rightDist, leftDist);
            ans.push_back(minDiff);
        }
        return ans;
    }
};
