class Solution {
  public:
    
    bool solve(vector<vector<int>> &v, unordered_map<int,bool> &vis,int node){
        
        bool ans = false;
        
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node] = true;
        
        while(!q.empty()){
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int neigh : v[front]){
                
                if(vis[neigh]){
                    
                    if(neigh != parent)
                    return true;
                    
                }else{
                    q.push({neigh,front});
                    vis[neigh] = true;
                }
            }
        }
        return false;
    }
    void prepareAdjList(vector<vector<int>> &v,vector<vector<int>>& edges){
        
        int E = edges.size();
        for(int i=0;i<E;i++){
            int fir = edges[i][0];
            int sec = edges[i][1];
            
            v[fir].push_back(sec);
            v[sec].push_back(fir);
        }
    }
    
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> v(V);
        prepareAdjList(v,edges);
        unordered_map<int,bool> vis;

        
        bool ans = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solve(v,vis,i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
