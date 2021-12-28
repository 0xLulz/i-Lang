#include "i_main.h"

iLang Build_Class(iLang *s) {
    return s;
}

void _setfile(iLang *i, iLang *file, iLang *filepath) {
    i->file = file;
    i->filepath = filepath;
}

void Operate(iLang *i) {

}