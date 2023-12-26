#include <stdio.h>
#include <stdlib.h>

#define STR_IMPLEMENTATION
#include "str.h"

int main(void) {
    // Test str_len
    printf("%lld\n", str_len("Hello"));
    
    // Test str_nlen
    printf("%lld\n", str_nlen("Hello", 7));
    printf("%lld\n", str_nlen("Hello", 5));
    printf("%lld\n", str_nlen("Hello", 2));
    
    // Test str_copy
    const char* src = "Hi";
    char* dest = calloc(sizeof(char), 4);
    str_copy(src, dest);
    printf("%s\n", dest);
    free(dest);

    // Test str_ncopy
    src = "Hellooo";
    dest = calloc(sizeof(char), 16);
    str_ncopy(src, dest, 3);
    printf("%s\n", dest);
    free(dest);

    dest = calloc(sizeof(char), 16);
    str_ncopy(src, dest, 25);
    printf("%s\n", dest);
    free(dest);
    
    return 0;
}
