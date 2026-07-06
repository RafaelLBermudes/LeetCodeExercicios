char repeatedCharacter(char* s) {
    int search[256] = {0}, tam = strlen(s);
    char output;
    for(int i = 0; i < tam; i++){
        int temp = s[i];
        search[temp]++;
        if(search[temp] >= 2){
            output = temp;
            return output;
        }
    }   
    return 0;
}
