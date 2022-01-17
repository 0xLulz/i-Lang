#include <stdio.h>
#include <stdlib.h>

#include "../i_lang/main.h"// ~/i_lang/main.h
#include "../i_lib/i_lib.h"// ~/i_lib/i_lib.h
#include "../i_lib/str_utils.h"// ~/i_lib/str_utils.h

iLang Build_iLang(iLang *i)
{
    util_zero(main_file, 64);
    main_filedata = NULL;
    main_imports = NULL;
    main_fnc_used = NULL;
    
}

void __operate(iLang *i, char *file) 
{
    char test[255];// test what?
}
