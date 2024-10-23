class DisjointSet{
    vector<int> rank , parent , size ;
    public:
	    DisjointSet(int n){
		    rank.resize(n + 1 , 0);
		    parent.resize(n + 1);
		    size.resize(n + 1);
	    	for(int i = 0 ; i <= n ; i++){
		      	parent[i] = i;	
			      size[i] = 1;
		  }
	}

    int findUpar(int node){
	     if(node == parent[node]){
			    return node;
		  }
	     return parent[node] = findUpar(parent[node]);
	}

     void unionByRank(int u , int v){
            int up_u = findUpar(u);
	          int up_v = findUpar(v);
	          if(up_u == up_v) return ;
	          if(rank[up_u] < rank[up_v]){
		            parent[up_u] = up_v;
	           }else if(rank[up_v] < rank[up_u]){
		            parent[up_v] = up_u;
	            }else{
		            parent[up_v] = up_u;
		            rank[up_u]++;	
	           }
     }

     void unionBysize(int u , int v){
	       int up_u = findUpar(u);
	       int up_v = findUpar(v);
	       if(up_u == up_v){
		        return ;
	       }else if(size[up_u] < size[up_v]){
		        parent[up_u] = up_v;
		        size[up_v] += size[up_u];
	       }else{
		        parent[up_v] = up_u;
		        size[up_u] += size[up_v];	
	     }
     }
};
