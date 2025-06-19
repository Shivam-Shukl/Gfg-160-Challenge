class Solution {
    
  public:
    void left(Node* root , vector<int> & ans)
    {
        if(!root)
            return;
            
        
        if(root -> left == NULL && root -> right == NULL)
        {
            return;
        }
        ans.push_back(root -> data);
        if(root -> left){
            left(root ->left,ans);
        }
        else{
            left(root -> right ,ans);
        }
    }
    void right(Node* root , vector<int> & ans)
    {
        if(!root)
            return;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            return;
        }
        ans.push_back(root -> data);
        if(root -> right){
            right(root ->right,ans);
        }
        else{
            right(root -> left ,ans);
        }
    }
    void leaf(Node* root , vector<int> &ans)
    {
        if(!root)
            return;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> data);
        }
        leaf(root -> left ,ans);
        leaf(root -> right , ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        vector<int> ans;
        if(!root){
            return ans;
        }else {
            ans.push_back(root ->data);
       
        }
        if(root -> left == NULL && root -> right == NULL)
        {
            return ans;
        }
        left(root->left,ans);
        leaf(root,ans);
        vector<int> v2;
        right(root-> right,v2);
        reverse(v2.begin(),v2.end());
        
        for(int i : v2)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
