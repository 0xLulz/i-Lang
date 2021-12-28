#ifndef I_MAIN_H
#define I_MAIN_H
typedef struct iLanguage {
    char        *file;
    char        *filepath;
    char        *line;
} iLang;
iLang Build_Class(iLang *i);
void Operate(iLang *i);
#endif
