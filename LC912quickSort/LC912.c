/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quickSort(int *nums, int left, int right) {
    int mid, tmp, i, j;
    i = left;
    j = right;
    mid = nums[ (left + right) / 2 ];

    do {

        while ( nums[i] < mid )
            i++;

        while ( nums[j] > mid )
            j--;

        if ( i <= j ) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }

    } while ( i <= j );

    if ( left < j )
        quickSort( nums, left, j );

    if ( right > i )
        quickSort( nums, i, right );

}
 
int* sortArray(int* nums, int numsSize, int* returnSize) {
    
    (*returnSize) = numsSize;

    quickSort( nums, 0, numsSize - 1 );

    return nums;
}
