class Solution {
  public:
    //Function to return resmum path sum from any node in a tree.\
    
    int helper(Node* root , int &res){
        if(root == NULL){
            return 0;
        }
     
        int leftSum = max(0,helper(root->left , res));
        int rightSum = max(0,helper(root->right , res));
        
        res = max(res,root->data + leftSum + rightSum);
        
        return root->data + max(leftSum , rightSum);
    }
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int res = INT_MIN;
        int TEMP = helper(root , res);
        return res;
    }
};
