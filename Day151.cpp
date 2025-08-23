class Solution {
  public:
    vector<int> topoSort(vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> order;
        vector<int> indegree(n, 0);
        for(int node = 0; node < n; node++){
            for(auto it:adj[node]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int node = 0; node < n; node++){
            if(!indegree[node]){
                q.push(node);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(!indegree[adjNode]){
                    q.push(adjNode);
                }
            }
        }
        
        if(order.size() == n){
            return order;
        }
        return {};
    }
    string findOrder(vector<string> &words) {
        // code here
        int V = 0;
        set<char> st;
        for(auto it: words){
            for(auto x: it){
                st.insert(x);
            }
        }
        unordered_map<char, int> mp;
        unordered_map<int, char> mp2;
        int mapper = 0;
        for(auto it: st){
            mp[it] = mapper;
            mp2[mapper] = it;
            mapper++;
        }
        vector<vector<int>> adj(st.size(), vector<int>(0, 0));
        int n = words.size();
        for(int i = 0; i < n-1; i++){
                string a = words[i];
                string b = words[i+1];
                int k = 0;
                while(k < a.size() && k < b.size()){
                    if(a[k] != b[k]){
                        int u = mp[a[k]];
                        int v = mp[b[k]];
                        adj[u].push_back(v);
                        break;
                    }
                    k++;
                    if(k != a.size() && k == b.size())
                        return "";
                }
        }
        
        vector<int> tSort;
        tSort = topoSort(adj);
        string ans = "";
        for(auto it: tSort){
            ans += mp2[it];
        }
        return ans;
    }
};

