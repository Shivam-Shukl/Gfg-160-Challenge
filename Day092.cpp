class Solution {
  public:
    
    pair<int,int> getele(vector<int> v)
    {
        int ele1 =0,ele2=0;
        int i=0,n = v.size();
        while(i<n-1)
        {
            if(v[i]>v[i+1])
            {
                ele1 = v[i];
                int j=i+1;
                int ans = INT_MAX;
                int index=0;
                while(j<n)
                {
                    if(ans>v[j])
                    {
                        ans = v[j];
                        index = j;
                    }
                    j++;
                }
                swap(v[i],v[index]);
                ele2 = ans;
            }
            i++;
        }
        return {ele1,ele2};
    }
    void solve(Node *root,int ele1 ,int ele2)
    {
        if(!root) return;
        
        if(root -> data ==  ele1) root -> data = ele2;
        else if(root -> data == ele2) root -> data = ele1;
        
        solve(root -> left,ele1,ele2);
        solve(root -> right,ele1,ele2);
    }
    void inorder(Node* root, vector<int> &v)
    {
        if(!root)
        {
            return;
        }
        inorder(root-> left, v);
        v.push_back(root -> data);
        inorder(root ->right , v);
    }
    void correctBST(Node* root) {
        // add code here.
        vector<int> v ;
        inorder(root,v);
        
        pair<int,int> p = getele(v);
        int ele1 = p.first ,ele2 = p.second;
        solve(root,ele1,ele2);
        
    }
};
