class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        //creating adjecency matrix
        vector<vector<int>>adj(n);
        //creating indegree array
        vector<int>indegree(n,0);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);    //ex1) 1 should be performed before 0 ie 1->0
            indegree[prerequisites[i][0]]++;
        }

        //create queue to store nodes
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        //create topo vector to store order
        vector<int>topo;

        //perform bfs
        while(!q.empty()){

            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }

        //check
        if(topo.size()==n) return topo;
        return {};
    }
};