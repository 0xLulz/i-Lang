#ifndef I_MAIN_H
#define I_MAIN_H
#include "errors.h"
#include "../i_lib/print.h"
typedef struct BuiltinStuff {
    char        **modules[255];
    char        **methods[255];
    char        **variables[255];
    char        **classes[255];
} Builtins;

typedef struct ExternalFunctions {
    char        **modules[255];
    char        **methods[255];
    char        **variables[255];
    char        **classes[255];
} ExternalFnc;

typedef struct Line_Checker {
    int         error_check;
    int         error_line;
    int         error_msg;
} CurrentLine;

typedef struct FunctionChecker {
    char        *fnc_name;
    char        **fnc_args[20];
    char        **fnc_returns[20];
} FncChecker;

typedef struct VariableChecker {
    int         total_vars;
    char        **var_type[255];
    char        **var_name[255];
    char        **var_value[255];
} VarChecker;

typedef struct iLangx {
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

void __operate(iLang *i, char *file) {
    char test[255];
}

iLang Build_iLang(iLang *i) {
    i->operate = __operate;
}
#endif
