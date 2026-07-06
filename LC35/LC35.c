int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    while ( high >= low ) {
        mid = low + ( high - low ) / 2;

        if ( nums[mid] == target )
            return mid;

        if ( nums[mid] < target )
            low = mid + 1;
        else
            high = mid - 1;

    }
    if ( nums[mid] > target )
        return mid;
    else
        return mid + 1;
}
