/**
 *  print_errno.c - Useful (I think) little utility to translate an errno
 *                  into a string.
 *
 *  MIT License
 *
 *  Copyright (c) 2015, Michael Becker (michael.f.becker@gmail.com)
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a 
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 *  and/or sell copies of the Software, and to permit persons to whom the 
 *  Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included 
 *  in all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
 *  OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR 
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


void usage(char *prgm_name)
{
    printf("%s [errno]\n", prgm_name);
    printf("  Translates a given errno into a system error string\n");
    printf("  using the library call strerror().\n");
}


int main (int argc, char *argv[])
{
    int error;
    char *end_ptr;

    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }

    error = strtol(argv[1], &end_ptr, 0);
    
    if (end_ptr == argv[1]){
        printf("Invalid input string - %s\n", argv[1]);
    }
    else if (error == LONG_MIN) {
        printf("Underflow on - %s\n", argv[1]);
    }
    else if (error == LONG_MAX) {
        printf("Overflow on - %s\n", argv[1]);
    }
    else {
        printf("errno: %d - %s\n", error, strerror(error));
    }

    return 0;
}


