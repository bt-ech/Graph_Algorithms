int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0 ; i < V ; i++){
            for(auto& u : adj[i]){
                int adjNode = u[0];
                int wt = u[1];
                edges.push_back({wt , {i , adjNode}});
            }
        }
        
        sort(edges.begin() , edges.end());
        
        int mst = 0 ;
        
        DisjointSet ds(V); /* Implement DSU */
        
        for(auto& u : edges){
            int wt = u.first;
            int node1 = u.second.first ;
            int node2 = u.second.second;
            
            if(ds.findUpar(node1) != ds.findUpar(node2)){
                mst += wt;
                ds.unionBysize(node1 , node2);
            }
        }
        return mst ;
