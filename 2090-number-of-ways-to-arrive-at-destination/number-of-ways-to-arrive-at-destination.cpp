class Solution {
    int MOD = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //construct adj array
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<roads.size(); i++){
            int from = roads[i][0];
            int to = roads[i][1];
            int time = roads[i][2];
            adj[from].push_back({to,time});         //{node,time}
            adj[to].push_back({from,time});         //{node,time}      //because undirected graph
        }

        vector<long long>distance(n,LLONG_MAX); //distance array to track shortest path
        vector<int>ways(n,0);  //array to keep track of number of ways
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq; 

        distance[0]=0; //we start from  0
        ways[0]=1; //since we start from 0
        pq.push({0,0}); //{time,node}

        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                //first time arriving with a short time
                if(wt+dist<distance[adjNode]){
                    distance[adjNode] = wt+dist;
                    ways[adjNode] = ways[node];
                    pq.push({wt+dist,adjNode});
                }
                else if(wt+dist==distance[adjNode]){
                    ways[adjNode] = (ways[node]+ways[adjNode])%MOD;
                }
            }
        }
        return (ways[n-1])%MOD;
    }
};