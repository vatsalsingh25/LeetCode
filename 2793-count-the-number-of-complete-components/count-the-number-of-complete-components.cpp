class Solution {
public:
    vector<int>bfs(int node, vector<vector<int>>adj, vector<int>&vis){
        int nodesCnt = 1;
        int edgesCnt = 0;

        vis[node]=1;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int vertex = q.front();
            q.pop();

            for(auto it: adj[vertex]){
                edgesCnt++;
                if(!vis[it]){
                    nodesCnt++;
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        return {nodesCnt,edgesCnt/2};

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
                vector<int>info = bfs(i,adj,vis);
                int node = info[0];
                int edges = info[1];
                if(node*(node-1)/2 == edges) count++;
            }
        }
        return count;
    }
};