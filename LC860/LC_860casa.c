bool lemonadeChange(int *bills, int billsSize) {
    int dinheiro[2] = { 0 };
    // Brute Force
    for ( int i = 0; i < billsSize; i++ ) {
        if ( bills[i] == 5 ) {
            dinheiro[0] += bills[i];
        } else if ( bills[i] == 10 ) {
            dinheiro[1] += 10;
            if ( dinheiro[0] < 5 ) {
                return false;
            }
            dinheiro[0] -= 5;
        } else {
            if ( dinheiro[1] >= 10 && dinheiro[0] >= 5 ) {
                dinheiro[1] -= 10;
                dinheiro[0] -= 5;
            } else if ( dinheiro[0] >= 15 ) {
                dinheiro[0] -= 15;
            } else {
                return false;
            }
        }
    }
    return true;
}
