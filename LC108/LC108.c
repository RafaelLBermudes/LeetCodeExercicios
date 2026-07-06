/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int altura (struct TreeNode *root) {

    if (root == NULL)
        return 0;

    int altEsq = altura(root->left);
    int altDir = altura(root->right);

    if ( altEsq > altDir )
        return 1 + altEsq;

    return 1 + altDir;
}

int FB (struct TreeNode *root) {
    if ( root == NULL )
        return 0;

    return altura(root->left) - altura(root->right);
}

struct TreeNode* criarArvore(int val) {
    struct TreeNode* new = (struct TreeNode* )malloc( sizeof( struct TreeNode ) );

    if ( new == NULL )
        return NULL;
    
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct TreeNode* RSD(struct TreeNode* root) {
    struct TreeNode* X = root->left;
    struct TreeNode* Y = X->right;
    X->right = root;
    root->left = Y;
    return X;
}

struct TreeNode* RSE(struct TreeNode* root) {
    struct TreeNode* X = root->right;
    struct TreeNode* Y = X->left;
    X->left = root;
    root->right = Y;
    return X;
}

struct TreeNode* inserir(struct TreeNode* root, int val ) {
    if (root == NULL)
        return criarArvore(val);

    if ( val < root->val ) 
        root->left = inserir(root->left, val);
    else if ( val >= root->val )
        root->right = inserir(root->right, val);
    else 
        return root;

    int fb = FB(root);

    if ( fb > 1 && val < root->left->val ) {
        return RSD(root);
    } 
    if (  fb < -1 && val > root->right->val ) {
        return RSE(root);
    }
    if ( fb > 1 && val > root->right->val ) {
        root->left = RSE(root);
        return RSD(root);
    }
    if ( fb < -1 && val < root->right->val ) {
        root->right = RSD(root);
        return RSE(root);
    }

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    struct TreeNode *root = NULL;

    for ( int i = 0; i < numsSize; i++ ) {
        root = inserir(root, nums[i]);
    }

    return root;
}
