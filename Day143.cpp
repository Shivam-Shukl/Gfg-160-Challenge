class Solution {
  public:
    void prepAdj(vector<vector<int>> &edges,vector<vector<int>> &adj){
        
        for(int i=0;i<edges.size();i++){
            int fir = edges[i][0];
            int sec = edges[i][1];
            adj[fir].push_back(sec);
        }
    }
    void dfs(vector<vector<int>> &adj,stack<int> &st,unordered_map<int,bool> &vis,int node){
        
        vis[node] = true;
        
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                dfs(adj,st,vis,adj[node][i]);
            }
        }
        st.push(node);
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        stack<int> st;
        prepAdj(edges,adj);
        unordered_map<int,bool> vis;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,st,vis,i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};