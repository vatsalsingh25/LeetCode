class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>hash;
        for(int i=0; i<arr.size(); i++){
            hash[arr[i]]++;
        }
        for(auto it: hash){
            pq.push({it.second,it.first});
        }
        int terms = 0;
        int ans = 0;
        while(!pq.empty()){
            if(terms < arr.size()/2){
                terms+=pq.top().first;
                pq.pop();
                ans++;
            }
            else break;
        }
        return ans;
    }
};