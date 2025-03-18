class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // assume all directions are reversed and then make a adj array
        vector<vector<int>>adjRev(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adjRev[graph[i][j]].push_back(i);
            }
        }

        vector<int>indegree(n,0);
        //calculate the indegree based on adjRev
        for(int i=0; i<n; i++){
            for(int j=0; j<adjRev[i].size(); j++){
                indegree[adjRev[i][j]]++;
            }
        }

        // push indegree = 0 values to queue
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;
        // perform the q operation and store values with subsequent 0s in ans array
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
        
    }
};