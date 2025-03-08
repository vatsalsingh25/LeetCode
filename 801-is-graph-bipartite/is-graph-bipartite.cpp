class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&vis, int color){
        vis[node]=color;  //giving the color to the prev node

        for(auto it: graph[node]){
            if(vis[it]!=-1){
                if(vis[it]==color) return false;
            }
            else{
                //dfs(it,graph,vis,1-color);
                if(dfs(it,graph,vis,1-color)==false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1); //visited array, also saves the color
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                //dfs(i,graph,vis,0);
                if(dfs(i,graph,vis,0)==false) return false;
            } 
        }
        return true;
    }
};