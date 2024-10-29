int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0 , 0});
        int sum = 0;
        vector<int> used(V , 0);
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first ;
            int node = it.second;
            
            pq.pop();
            
            if(used[node] == 1){
                continue;
            }
            
            used[node] = 1;
            sum += wt;
            
            for(auto& u : adj[node]){
                int adjNode = u[0];
                int adjwt = u[1];
                if(!used[adjNode]){
                    pq.push({adjwt , adjNode});
                }
            }
        }
        return sum;
    }
