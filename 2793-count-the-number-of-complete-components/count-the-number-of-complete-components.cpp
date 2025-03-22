class Solution {
public:
    void dfs(int node, vector<vector<int>>adj, vector<int>&vis, int& nodesCnt, int& edgesCnt){
        vis[node]=1;
        nodesCnt++;
        
        for(auto it: adj[node]){
            edgesCnt++;
            if(!vis[it]){
                dfs(it,adj,vis,nodesCnt,edgesCnt);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int nodesCnt =0;
                int edgesCnt = 0;
                dfs(i,adj,vis,nodesCnt,edgesCnt);
                if(nodesCnt*(nodesCnt-1)/2 == edgesCnt/2) count++;    //each edge is counted twice, hence edges/2 
            }
        }
        return count;
    }
};