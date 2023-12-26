#ifndef _STR_H_
#define _STR_H_

/**
 *  str.h
 *  is a C99 compatible, STB-Style library for strings.
 *  
 *  In order to actually use the implementation of this library, you need to define STR_IMPLEMENTATION.
 *  Example:
 *      #define STR_IMPLEMENTATION
 *      #include "str.h"
 *
 *  License:
 *  MIT License
 *
 *  Copyright (c) 2023 Tim Teichmann
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/**
 *  str_len
 *  Find out the length of a null-terminated C-string.
 *  
 *  Params:
 *      str: The string of interest.
 *
 *  Return value:
 *      SUCCESS: The length of str.
 *      FAILURE: -1
 *
 *  NOTE: str will remain unchanged
 */
long long str_len(const char* str);

/**
 *  str_nlen
 *  Find out the length of a null-terminated C-string.
 *  
 *  Params:
 *      str: The string of interest.
 *      n: str_nlen will stop counting if str is longer than n
 *
 *  Return value:
 *      SUCCESS: The length of str.
 *      FAILURE: -1
 *      N-REACHED: n
 *
 *  NOTE: str will remain unchanged
 */
long long str_nlen(const char* str, long long n);

/**
 *  str_copy
 *  Copy a C-string from src to dest.
 *  
 *  Params:
 *      src: The string to be copied.
 *      dest: The location of the copied string.
 *
 *  Return value:
 *      SUCCESS: Pointer to dest
 *      FAILURE: NULL
 *
 *  NOTE: 
 *      - src will remain unchanged while dest will be modified
 *      - dest should be bigger or as big as src
 */
char* str_copy(const char* src, char* dest);

/**
 *  str_ncopy
 *  Copy n characters of a C-string from src to dest.
 *  
 *  Params:
 *      src: The string to be copied.
 *      dest: The location of the copied string.
 *      n: Maximum amount of chars.
 *
 *  Return value:
 *      SUCCESS: Pointer to dest
 *      FAILURE: NULL
 *      N-REACHED: If n was reached, dest will contain the first n characters of src.
 *
 *  NOTE: src will remain unchanged while dest will be modified
 */
char* str_ncopy(const char* src, char* dest, long long n);

/**
 *  str_eat_spaces
 *  Eat (remove) all spaces of a string.
 *  
 *  Params:
 *      str: The string to perform action on
 *
 *  Return value:
 *      SUCCESS: Pointer to src
 *      FAILURE: NULL
 */
char* str_eat_spaces(char* str);

#endif // !_STR_H_

#ifdef STR_IMPLEMENTATION

long long str_len(const char* str) {
    if (!str) return -1;

    long long count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

long long str_nlen(const char* str, long long n) {
    if (!str) return -1;

    long long count = 0;
    while (str[count] != '\0' && count < n) {
        count++;
    }
    return count;
}

char* str_copy(const char* src, char* dest) {
    if (!src || !dest) return NULL;

    long long len = str_len(src);
    if (len == -1) return NULL;
    
    for (long long l = 0; l < len; ++l) {
        dest[l] = src[l];
    }
    return dest;
}

char* str_ncopy(const char* src, char* dest, long long n) {
    if (!src || !dest) return NULL;

    long long len = str_nlen(src, n);
    if (len == -1) return NULL;
    
    for (long long l = 0; l < len; ++l) {
        dest[l] = src[l];
    }
    return dest;
}

char* str_eat_spaces(char* str) {
    
}

#endif // STR_IMPLEMENTATION
