/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
     string serialize(TreeNode* root) 
    {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
	
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return buildTree(ss);
    }
    
private:
    
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }
};
