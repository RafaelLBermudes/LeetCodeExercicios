/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root) {
    if ( root == NULL )
        return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return 1 + (lHeight > rHeight ? lHeight : rHeight);
}

bool isBalanced(struct TreeNode* root) {

    if ( root == NULL )
        return true;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if ( abs(lHeight - rHeight) > 1 )
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}
