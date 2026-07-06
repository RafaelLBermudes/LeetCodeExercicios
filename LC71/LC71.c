char* simplifyPath(char* path) {
    int top = 0, tam = strlen(path), walk = 0;
    if ( tam < 2 ) {
        return path;
    }
    char stack[tam+1];

    stack[top] = '/';
    top++;
    for ( int i = 1; i < tam; i++ ) {
        stack[top] = path[i];
        top++;
        if ( ( stack[top-1] == '/' && path[i+1] == '/' ) || ( top >= 2 && stack[top-2] == '/' && stack[top-1] == '/' ) ) { // verifica caso de várias barras juntas
            stack[top-1] = '\0';
            top--;
        } else if ( top >= 2 && stack[top-2] == '/' && stack[top-1] == '.' && ( path[i+1] == '\0' || path[i+1] == '/' ) ) { // verifica caso de /./
            stack[top-1] = '\0';
            top--;
        } else if ( top > 3 && stack[top-3] == '/' && stack[top-2] == '.' && stack[top-1] == '.' && path[i+1] != '.' && ( path[i+1] == '/' || path[i+1] == '\0' ) ) { // verifica caso de /algumdiretorio/../
            top -= 4;
            while ( stack[top] != '/' ) {
                top--;
            }
            stack[top] = '/';
            stack[top+1] = '\0';
            top++;
        } else if ( top < 4 && top > 1 && stack[top-2] == '.' && stack[top-1] == '.' && path[i+1] != '.' && ( path[i+1] == '/' || path[i+1] == '\0' ) ) { // verifica caso de /../
            top = 1;
            stack[1] = '\0';
        } 
    }
    stack[top] = '\0';
    if ( stack[top-1] == '/' && top > 2 ) {
        stack[top-1] = '\0';
    }

    char *sPath = malloc( sizeof(char) * ( strlen( stack ) + 1 ) ); 
    strcpy(sPath, stack);

    return sPath;
}

/* 
Casos: 
    - várias barras juntas -> remover todas barras que não tenham nada a direita
    - . sem nenhum ponto em volta -> só remover o ponto
    - .. sem outros pontos em volta -> remover os 2 pontos e o diretório anterior
Lógica
    empilha na pilha e caso ache um dos casos acima desempilha até onde tal caso precise
    depois ao acabar usa strcpy pra copiar a string que sobrou do stack
*/
