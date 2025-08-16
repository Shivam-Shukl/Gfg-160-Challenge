class Solution {
  public:
    void prep(int V,vector<vector<int>> &edges,unordered_map<int,vector<int>> &adj){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            
            if(adj.find(i)== adj.end()){
                vector<int> v;
                adj[i] = v;
            }
        }
    }
 
    
    bool dfs(unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis,
            unordered_map<int,bool> &dfsV,int node){
        
        vis[node] = true;
        dfsV[node] = true;
        
        vector<int> v = adj[node];
        for(int neigh: v){
            if(vis[neigh] && dfsV[neigh]){
                return true;
            }else{
                if(!vis[neigh]){
                    if(dfs(adj,vis,dfsV,neigh)) return true;
                }
            }
        }
        dfsV[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>> adj;
        prep(V,edges,adj);
        unordered_map<int,bool> vis;
        unordered_map<int,bool>dfsV;
        
        bool ans = false;
        for(auto it = adj.begin() ;it!= adj.end();it++){
            if(!vis[it->first]){
                ans = ans || dfs(adj,vis,dfsV,it->first);
            }
        }
        
     
        return ans;
    }
};
