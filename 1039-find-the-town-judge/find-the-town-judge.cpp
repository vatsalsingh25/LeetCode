class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        vector<int>hash(n+1,0);
        for(int i=0; i<trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            adj[u].push_back(v);
            hash[v]++;
        }
        for(int i=1; i<=n; i++){
            if(adj[i].size()==0 && hash[i]==n-1) return i;
        }

        return -1;
    }
    // 0: 
    // 1: 2
    // 2: 3
    // 3: 
};