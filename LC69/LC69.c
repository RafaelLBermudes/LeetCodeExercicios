int mySqrt(int x) {
    if ( x == 0 )
        return 0;

    int low = 0, high = x, mid, test;

    while ( high >= low ) {
        mid = low + ( high - low ) / 2;
        if ( mid == 0 )
            mid = 1;
        test = x / mid;

        if ( test == mid ) 
            return mid;
        
        if ( test > mid )
            low = mid + 1;
        else
            high = mid - 1;

    }

    if ( test > mid)
        return mid;
    else
        return mid - 1;
}
