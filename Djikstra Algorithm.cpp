vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i = 0 ;i < V ; i++){
            dist[i] = 1e9 ;
        }
        
        dist[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int node = pq.top().second ;
            int dis = pq.top().first ;
            pq.pop();
            
            for(auto& u : adj[node]){
                int AdjNode = u[0];
                int EdgeWeight = u[1];
                
                if(dis + EdgeWeight < dist[AdjNode]){
                    dist[AdjNode] = dis + EdgeWeight;
                    pq.push({dist[AdjNode] , AdjNode});
                }
            }
        }
        
        return dist ;
        
    }
