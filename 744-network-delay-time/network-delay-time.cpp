class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //create adjecency matrix
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0; i<times.size(); i++){
            int from = times[i][0];
            int to = times[i][1];
            int time = times[i][2];
            adj[from].push_back({to,time});
        }

        //{time,{from,to}}
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int>distance(n+1,INT_MAX);  //1 based indexing
        distance[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dist+wt < distance[adjNode]){
                    distance[adjNode] = wt+dist;
                    pq.push({wt+dist,adjNode});
                }
            } 
        }   

        //minimum time to reach all nodes would be equal to the maximum time signal takes to reach furthest node
        int maxi = INT_MIN;
        for(int i=1; i<n+1; i++){
            if(distance[i]==INT_MAX) return -1;
            if(distance[i]>maxi) maxi = distance[i];
        }   
        return maxi;       
    }
};