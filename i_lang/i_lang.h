#pragma once

//what i see here is about wrong... it will work

// try moving to a .c and leaving function definitions here to know that functoin exists in the same .c as .h

#include "errors.h"
#include "../i_lib/print.h"

typedef struct BuiltinStuff_t {// dude put this better be your libs i stg....
    char        **modules;
    char        **methods;
    char        **variables;
    char        **classes;
} Builtins;

typedef struct ExternalFunctions_t {// dude this better be my libs i stg...
    char        **modules;
    char        **methods;
    char        **variables;
    char        **classes;
} ExternalFnc;

typedef struct Line_Checker_t {// dude put this in the FunctionChecker_t
    int         error_check;
    int         error_line;
    int         error_msg;
} CurrentLine;

typedef struct FunctionChecker_t {
    char        fnc_name[64];// add this to defines #define ILANG_FUNC_NAME_SIZE_MAX 64
    int         fnc_args_count;
    int         fnc_returns_count;
    char        **fnc_args;
    char        **fnc_returns;
} FncChecker;

typedef struct VariableChecker_t {// dude put this in the FunctionChecker_t
    int         total_vars;// alr this is terrible its padded to the max... 1 byte left over
    char        **var_typs;
    char        **var_name;
    char        **var_value;
} VarChecker;

typedef struct iLang_t {
    char        main_file[64];// again add ILANG_MAIN_FILE_NAME_SIZE_MAX 64
    char        *main_filedata;// please tell me what this is?
    char        **main_imports;
    char        **main_fnc_used;
    //alr make all these function poniters or another struct to more function pointers
    // for initalization of these bitches at all....
    // pointers need malloc or calloc or realloc.....
    // even mmap or shm so???
    
    CurrentLine *line_check;// fuck it make it all save this
    FncChecker  *fnc_check;// and then have it backwards pointed to the FncChecker
    VarChecker  *var_check;// with everything else so
    Builtins    *builtin;// it can id everything in the compile
    ExternalFnc *extfnc;// from the fnc_name in FucktionChecker_t
    Error       *err;// or this will all be errors

    void*       (*operate)(struct iLang *i, char *file);
} iLang;

void __operate(iLang *i, char *file);// compile botnet
iLang Build_iLang(iLang *i);         // initalize the whole damn shit
