/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *ptr = root;
    struct TreeNode *res = NULL;

    if ( ptr == NULL )
        return NULL;

    while ( ptr != NULL ) {
        if ( ptr->val == val) {
            res = ptr;
            break;
        }
        if ( ptr->val > val )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return res;
}
