class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        //create adj vector
        vector<vector<pair<int,int>>>adj(n);               //[ [{node,cost},{},{}], [{node,cost},{},{}], .... ]
        for(int i=0; i<flights.size(); i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            adj[from].push_back({to,cost});
        }

        queue<pair<int,pair<int,int>>>q;  //{stops,{node,cost}}
        vector<int>distance(n,INT_MAX);

        q.push({0,{src,0}});
        distance[src] = 0;

        while(!q.empty()){
            int stops = q.front().first; 
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops>k) continue;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int newCost = it.second + cost;

                if(newCost<distance[adjNode] && stops<=k){
                    distance[adjNode] = newCost;
                    q.push({stops+1,{adjNode,newCost}});
                }
            }
        }

        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};