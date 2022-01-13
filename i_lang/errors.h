#ifndef ERRORS_H
#define ERRORS_H
typedef struct Errors {
    char        **Errors[255];
    char        **Error_Files[255];
    int         Error_Lines[255];
    int         Error_Count[255];
    void*       (*add_error)(struct Error *e, char *err_file, int err_line, char *err);
    void*       (*die)(char *msg);
} Error;

void __adderr(Error *e, char *err_file, int err_line, char *err) {

}

void err_n_die(char *msg) {
    printf("test");
    printf("%s", msg);
    exit(0);
}

Error Build_Error(Error *e) {
    e->add_error = __adderr;
    e->die = err_n_die;
}
#endif