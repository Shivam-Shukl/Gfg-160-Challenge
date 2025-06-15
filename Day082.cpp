class Solution {
  public:
    // Function to find the height of a binary tree.
    int solve(Node* root, int &diameter)
    {
        if(root== nullptr)
        {
            return 0;
        }
        int left = solve(root-> left ,diameter);
        int right = solve(root -> right, diameter);
        
        int curr = left + right ;
        diameter  = max(curr,diameter);
        return max(left,right) +1;
    }
    
    int diameter(Node* node) {
        // code here
        int diameter =0;
        solve(node,diameter);
        return diameter;
    }
};
