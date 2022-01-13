#pragma once
#ifndef PRINT_H
#define PRINT_H
void print(char *str, int nline) {
    char *output = malloc(sizeof(char *)*255+5);
    strcpy(output, str);
    if(nline == 1) strcat(output, "\r\n");
    printf("%s", output);
    free(output);
}

void iprint(char *str, int nline, int r, int c) {
    
}
#endif