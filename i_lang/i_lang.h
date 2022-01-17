#pragma once

//what i see here is about wrong... it will work

// try moving to a .c and leaving function definitions here to know that functoin exists in the same .c as .h

#include "errors.h"
#include "../i_lib/print.h"

typedef struct BuiltinStuff_t {
    char        **modules[255];
    char        **methods[255];
    char        **variables[255];
    char        **classes[255];
} Builtins;

typedef struct ExternalFunctions_t {
    char        **modules[255];
    char        **methods[255];
    char        **variables[255];
    char        **classes[255];
} ExternalFnc;

typedef struct Line_Checker_t {
    int         error_check;
    int         error_line;
    int         error_msg;
} CurrentLine;

typedef struct FunctionChecker_t {
    char        *fnc_name;
    char        **fnc_args[20];
    char        **fnc_returns[20];
} FncChecker;

typedef struct VariableChecker_t {
    int         total_vars;
    char        **var_type[255];
    char        **var_name[255];
    char        **var_value[255];
} VarChecker;

typedef struct iLang_t {
    char        *main_file[255];
    char        *main_filedata[255];
    char        **main_imports[255];
    char        **main_fnc_used[255];
    CurrentLine *line_check;
    FncChecker  *fnc_check;
    VarChecker  *var_check;
    Builtins    *builtin;
    ExternalFnc *extfnc;
    Error       *err;
    void*       (*operate)(struct iLang *i, char *file);
} iLang;

void __operate(iLang *i, char *file);
iLang Build_iLang(iLang *i);
