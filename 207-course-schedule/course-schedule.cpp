class Solution {
private:
    bool dfs( int node, vector<int>&vis, vector<vector<int>>&adj, vector<int>&pathVis){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]) {
                if( dfs(it,vis,adj,pathVis) == true ) return true;
            }
            else{
                if(pathVis[it]==1) return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        //creating adjecency matrix
        vector<vector<int>>adj(n);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);    //ex1) 1 should be performed before 0 ie 1->0
        }

        // create visited array
        vector<int>vis(n,0);
        // create path visited array
        vector<int>pathVis(n,0);
        //iterate over visited and call dfs for not visted nodes
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,pathVis)==true) return false;
            }
        }
        return true;
    }
};