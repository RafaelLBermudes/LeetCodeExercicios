/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if ( root == NULL ) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode *fila[2001];
    int inicio = 0, fim = 0;

    fila[fim++] = root;
    int **res = malloc( sizeof( *res ) * 2000 );
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * 2000 );

    while ( inicio < fim ) {
        int tam = (*returnColumnSizes)[*returnSize] = (fim - inicio) % 2001;
        res[*returnSize] = malloc(sizeof(**res) * tam);
        for ( int i = 0; i < tam; i++ ) {
            struct TreeNode *curr = fila[inicio++ % 2001];

            res[*returnSize][i] = curr->val;

            if(curr->left != NULL) 
                fila[fim++] = curr->left;
                
            if(curr->right != NULL)
                fila[fim++] = curr->right;
        }
        (*returnSize)++;
    }

    return res;
}
