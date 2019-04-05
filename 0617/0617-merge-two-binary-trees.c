/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode* t = t1;
    if(NULL == t1)
        return t2;
    if(NULL == t2)
        return t1;
    t->val = t1->val+t2->val;
    t->left = mergeTrees(t1->left,t2->left);
    t->right = mergeTrees(t1->right,t2->right);
    return t;
}