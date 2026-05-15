/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int top = -1, *stack = malloc( sizeof(int) * numsSize ), i = 0, flag = 0;
    *returnSize = numsSize;

    while ( i < numsSize ) {
        top++;
        stack[top] = nums[i]; 
        // bota no stack
        int x = top + 1;
        if ( x == numsSize ) {
            x = 0;
            // arruma o x caso ele acesse memória inválida
        }
        while ( x != top ) { 
            // anda no array apartir desse termo pra achar o próximo termo maior
            if( stack[top] < nums[x] ) {
                stack[top] = nums[x];
                flag = 1; 
                // se achar dá break e continua o while
                break;
            }
            if ( x == numsSize - 1 && top != 0 ) { 
                // caso não ache e chegue no fim do array volta pro inicio pra percorrer todo o array circularmente
                x = -1;
            } else if ( x == numsSize - 1 ) {
                break;
            }
            x++;
        }
        if ( flag == 0 ) {
            // caso não ache volta -1 pois não tem termo maior
            stack[top] = -1;
        }
        flag = 0;
        // redefine flag para 0 para continuar proximos loops
        i++;
    }

    return stack;
}
