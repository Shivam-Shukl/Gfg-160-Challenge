class Solution {
  public:
    int solve(Node* node )
    {
        if(node == NULL)
            return 0;
        
        int left = 1+ solve(node->left);
        int right = 1+ solve(node -> right);
        
        return max(left,right);
    }
    int height(Node* node) {
        // code here
        return solve(node)-1;
    }
};
