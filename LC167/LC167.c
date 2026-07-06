/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int high = numbersSize - 1, low = 0;

    while ( high >= low ) {
        int soma = numbers[low] + numbers[high];
        if ( soma == target ) {
            *returnSize = 2;
            int *result = malloc( sizeof(int) * 2 );
            result[0] = low + 1;
            result[1] = high + 1;
            return result;
        }
        if ( soma > target ) 
            high--;
        else 
            low++;
    }
    int *result;
    return result;
}
