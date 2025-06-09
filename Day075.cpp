class Solution {
  public:
    void solve(int index, string s,set<string> & st)
    {
        if(index == s.size())
        {
            st.insert(s);
            return ;
        }
        
        for(int i = index;i<s.size();i++)
        {
            swap(s[i],s[index]);
            solve(index+1,s,st);
            swap(s[i],s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> st;
        
        solve(0,s,st);
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};
