#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "i_lang/main.h"

int main(int argc, char **argv[]) {
    iLang i; Error e;
    Build_iLang(&i); Build_Error(&e);
    print("Starting up....", 1);
    if(argc < 1) e.die("[x] Error, Invalid Argument");

    for(int i = 0; i <= strlen(argv); i++) {
        if(argv[i] == NULL) continue;
        if(strstr(argv[i], ".i")) {
            print(argv[i], 1);
        }
        // If no file has been found then dont do anything. a file has to be found first

        // if(strstr(argv[i], "")) left off here
    }
    i.operate(&i, "test.i");
}