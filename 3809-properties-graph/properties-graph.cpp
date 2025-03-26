class Solution {
public:
    int intersect(vector<int>&arr1, vector<int>&arr2){
        unordered_set<int>hash1(arr1.begin(), arr1.end());

        int count = 0;
        for(auto it: arr2){
            if(hash1.find(it)!=hash1.end()){
                hash1.erase(it);
                count++;
            } 
        }
        return count;
    }
    void bfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        queue<int>q;
        vis[node] = 1;

        q.push(node);

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            for(auto it: adj[currNode]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();

        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i!=j){
                    if( intersect(properties[i], properties[j]) >= k){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }

                }
            }
        }

        vector<int>vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                count++;
            }
        }

        return count;
    }
};