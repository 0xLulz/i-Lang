#ifndef I_MAIN_H
#define I_MAIN_H
typedef struct iLanguage {
    char        *main_i_file;
    char        **main_imports[255];
    char        **main_fnc_used[255];
    LineChecker **Line_check;
    FncChecker  **fnc_checker;
    VarChecker  **var_check;
} iLang;

typedef struct CurrentLine {
    int         *error_check;
    int         *error_line;
    int         **error_msg;
}   LineChecker;

typedef struct FunctionChecker {
    int         fnc_count;
    char        *fnc_name;
    char        **fnc_args[255];
    char        **fnc_return[255];
} FncChecker;


//Gonnah have a detector for data type
typedef struct VariableChecker {
    int         var_count;
    char        **var_type[255];
    char        **var_name[255];
    char        **var_value[255];
    
} VarChecker;

typedef struct ExternalFnc {

}

iLang Build_Class(iLang *i);
void Operate(iLang *i);
#endif
