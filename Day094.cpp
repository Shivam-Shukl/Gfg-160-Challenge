class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.

    void solve(Node* root , vector<int> &v)
    {
        if(!root)
        {
            v.push_back(-1);
            return;
        }
        v.push_back(root -> data);
        solve(root -> left, v);
        solve(root -> right, v);
    }
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> v;
        solve(root,v);
        return v;
    }
    Node* helper(vector<int>& arr, int &index) {
        if (index >= arr.size() || arr[index] == -1) {
            index++;
            return nullptr;
        }
        Node* root = new Node(arr[index]);
        index++;
        root->left = helper(arr, index);
        root->right = helper(arr, index);
        return root;
    }
    
    Node* deSerialize(vector<int>& arr) {
        int index = 0;
        Node* root = helper(arr, index);
        return root;
    }

};
