class Solution {
public:
    Node* solve(const vector<int> &inorder, const vector<int> &preorder, 
                unordered_map<int, int> &mp, int &index, int start, int end) {
        if (start > end) return nullptr;

        Node* root = new Node(preorder[index++]); 
        int pos = mp[root->data];

        root->left = solve(inorder, preorder, mp, index, start, pos - 1);
        root->right = solve(inorder, preorder, mp, index, pos + 1, end);
        
        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();

        // Create the index mapping in one pass
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int index = 0;
        return solve(inorder, preorder, mp, index, 0, n - 1);
    }
};
