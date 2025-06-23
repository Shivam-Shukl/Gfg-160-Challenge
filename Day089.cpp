class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inOrder(Node* root , vector<int> &ans)
    {
        if(!root)
        {
            return;
        }
        inOrder(root->left , ans);
        ans.push_back(root -> data);
        inOrder(root -> right , ans);
    }
    bool isSorted(vector<int> ans){
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i-1] > ans[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isBST(Node* root) {
        // Your code here
        vector<int> ans;
        inOrder(root,ans);
        return isSorted(ans);
    }
};
