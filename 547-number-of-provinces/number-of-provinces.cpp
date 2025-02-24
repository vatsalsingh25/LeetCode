class Solution {
private: 
    //implementing dfs traversal algo
    void dfs(int node, vector<vector<int>>&adj, vector<int>&visited){
        visited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]) dfs(it,adj,visited);                
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        //creating adj list (from given matrix)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>visited(n,0);
        //finding all the starting point to traverse all the connected nodes ie province
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};