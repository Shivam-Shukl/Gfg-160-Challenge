class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<bool>vis(26, false);
        int ans =0;
        int start = 0,end =0;
        int n =s.length();
        while(end <n)
        {
            
            while(vis[s[end]-'a'] == true)
            {
                vis[s[start]-'a'] = false;
                start++;
            }
            vis[s[end]-'a'] = true;
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
