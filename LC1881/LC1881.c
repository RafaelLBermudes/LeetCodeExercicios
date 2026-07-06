char* maxValue(char* n, int x) {

    int i, j = 0, troca = 0, tam = strlen(n);
    char alvo = x + '0', *max = (char *) malloc((tam + 2    ) * sizeof(char));

    if ( n[0] == '-' ) {
        max[0] = '-';
        j++;
        for ( i = 1; i < tam + 1; i++ ) {
            if ( (n[i] > alvo || n[i] == '\0') && troca != 1) {
                max[j] = x + '0'; 
                troca = 1;
                j++;
                i--;
            } else {
                max[j] = n[i];
                j++;
            }
        }
        max[j-1] = '\0';
    } else {
        for ( i = 0; i < tam + 1; i++ ) {
            if ( (n[i] < alvo || n[i] == '\0') && troca != 1) {
                max[j] = x + '0'; 
                troca = 1;
                j++;
                i--;
            } else {
                max[j] = n[i];
                j++;
            }
        }
        max[j-1] = '\0';
    }
    return max;
}
