#include <stdio.h>

/*
 * Process string: remove smiles like :-)) or :-(((.
 */

int main(void) {
    char str[] = "Remov:-(((((e smiles :-) like ':-))))' or ':-('";

    int r, w;
    r = 0;
    w = 0;
    int smile = 0;
    while (str[r]) {
        printf("%s %d %d %d\n", (char*)str, r, w, smile);
 
        if (str[r] == ':') {
            smile = 1;
        } else if ( (str[r] == '-') && (smile == 1) ) {
            smile = 2;
        } else if ( (smile >= 2) && ( (str[r] == ')') || (str[r] == '(') ) ) {
            smile ++;
        } else {
            if (smile >= 3) {
                w -= smile;
            }
            smile = 0;
        }
        str[w++] = str[r++];
    }
    str[w] = '\0';
    printf("%s\n", str);
    
    return 0;
}