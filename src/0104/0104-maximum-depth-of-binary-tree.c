/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int depth = 1;
    int left = 0;
    int right = 0;
    
    if(NULL == root)
        return 0;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    depth +=left >right?left:right;
    return depth;
}