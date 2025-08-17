class Solution {
  public:
    void prep(vector<vector<int>> &adj,vector<vector<int>> &edges,int c, int d){
        
        for(int i= 0;i<edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            // we are not marking the edges between the target nodes so that
            // we can ceck later.
            if((u == c && v == d )|| (v == c && v== d)) continue;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
   
    
    void bfs(vector<vector<int>> adj, int node,unordered_map<int,bool> &vis){
        
        queue<int> q;
        q.push(node);
        
        vis[node] = true;
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            for(int neigh : adj[front]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V); 
        
        prep(adj,edges,c,d);  // preparing the modified graph stucture
        
        unordered_map<int,bool> vis;  // vis to track the node
        
        bfs(adj,c,vis); // passing one edges as firsst point and if other can be reached 
        
        return !vis[d];// return fianl answe
    }
};
