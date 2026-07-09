void merge( int *nums, int left, int mid, int right ) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc( n1 * sizeof(int) );
    int *R = malloc( n2 * sizeof(int) );
    if ( L == NULL || R == NULL ) {
        free( L );
        free( R );
        return;
    }

    for ( i = 0; i < n1; i++ )
        L[i] = nums[left + i];
    for ( j = 0; j < n2; j++ )
        R[j] = nums[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while ( i < n1 && j < n2 ) {
        if ( L[i] <= R[j] ) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while ( i < n1 ) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while ( j < n2 ) {
        nums[k] = R[j];
        j++;
        k++;
    }

    free( L );
    free( R );

}

void mergeSort( int *nums, int left, int right ) {
    if ( right > left ) {
        int mid = left + ( right - left ) / 2;

        mergeSort( nums, left, mid );
        mergeSort( nums, mid + 1, right );

        merge( nums, left, mid, right );
    }
} 

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    mergeSort( nums, 0, numsSize - 1 );
    int linhas = 0;
    int capacidade = 16;
    int **resNums = malloc( capacidade * sizeof(int *) );
    *returnColumnSizes = malloc( capacidade * sizeof(int) );
    (*returnSize) = 0;

    for ( int i = 0; i < numsSize - 2; i++ ) {
        if ( i > 0 && i < numsSize - 2 && nums[i] == nums[i-1] )
            continue;
        int j = i + 1;
        int k = numsSize - 1;
        while ( j < k ) {
            if ( j > i + 1 && j < numsSize - 1 && j < k && nums[j] == nums[j-1] ) {
                j++;
                continue;
            }
            if ( k < numsSize - 1 && k > 0 && nums[k] == nums[k+1] ) {
                k--;
                continue;
            }
            int res = nums[i] + nums[j] + nums[k];
            if ( res > 0 )
                k--;
            else if ( res < 0 )
                j++;
            else if ( res == 0 ) {
                if ( linhas == capacidade ) {
                    int novaCapacidade = capacidade * 2;
                    int **tempRes = realloc( resNums, novaCapacidade * sizeof(int *) );
                    int *tempCols = realloc( *returnColumnSizes, novaCapacidade * sizeof(int) );
                    capacidade = novaCapacidade;
                    resNums = tempRes;
                    *returnColumnSizes = tempCols;
                }

                resNums[linhas] = malloc( 3 * sizeof(int) );

                (*returnColumnSizes)[linhas] = 3;
                resNums[linhas][0] = nums[i];
                resNums[linhas][1] = nums[j];
                resNums[linhas][2] = nums[k];
                linhas++;
                (*returnSize) = linhas;
                j++;
                k--;
            }
        }
    }

    return resNums;
}
