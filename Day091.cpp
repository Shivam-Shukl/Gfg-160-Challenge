class Solution {
  public:
    void solve(Node* root, int target,unordered_map<int,int> &mp,bool &ans)
    {
        if(!root)
            return;
        
        int val = root -> data;
        if(mp.find(target - val) != mp.end())
        {
            ans = true;
            return;
        }
        mp[root -> data]++;
        solve(root -> left,target,mp,ans);
        solve(root -> right, target,mp,ans);
        
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        unordered_map<int,int> mp;
        bool ans = false;
        solve(root,target,mp,ans);
        return ans;
    }
};
