/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void travel (struct TreeNode* root, int *result, int *sup) {
    if ( *sup > *result)
        *result = *sup;
    if ( root == NULL) {
        return;
    }
    if ( root->left != NULL ) {
        (*sup)++;
        travel (root->left, result, sup);
        (*sup)--;
    } 
    if ( root->right != NULL ) {
        (*sup)++;
        travel (root->right, result, sup);
        (*sup)--;
    }
}

int maxDepth(struct TreeNode* root) {
    if ( root == NULL )
        return 0;
    int result = 1, sup = 1;
    travel (root, &result, &sup);
    return result;
}
