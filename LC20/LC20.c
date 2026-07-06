bool isValid(char* s) {
    int tam = strlen(s);
    if ( tam % 2 == 1 ) {
        return false;
    }
    char brackets[tam];
    int top = 0;
    int walk = 0;

    for ( int i = 0; i < tam; i++ ) {
        if ( s[walk] == '(' || s[walk] == '[' || s[walk] == '{' ) {
            brackets[top] = s[walk];
            top++;
        } else if ( top > 0 && brackets[top-1] == '(' && s[walk] == ')' ) {
            top--;
            brackets[top] = '\0';
        } else if ( top > 0 && brackets[top-1] == '[' && s[walk] == ']' ) {
            top--;
            brackets[top] = '\0';
        } else if ( top > 0 && brackets[top-1] == '{' && s[walk] == '}' ) {
            top--;
            brackets[top] = '\0';
        } else {
            return false;
        }
        walk++;
    }
    if ( top != 0 ) {
        return false;
    }
    return true;
}
