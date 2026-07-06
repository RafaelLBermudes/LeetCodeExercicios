/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val) {
    struct TreeNode* new = (struct TreeNode*) malloc( sizeof( struct TreeNode ) );
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* prev = NULL;
    struct TreeNode* curr = root;

    while ( curr != NULL ) {
        prev = curr;
        if ( curr->val > val) {
            curr = prev->left;
        } else {
            curr = prev->right;
        }
    }
    curr = createNode( val );

    if ( prev == NULL )
        return curr;
    if ( prev->val > val )
        prev->left = curr;
    else
        prev->right = curr;
    return root;
}
