#ifndef STR_UTILS_H
#define STR_UTILS_H
void str__replace(const char *str, const char *find, const char *replacement, const char *dest) {
    char *new_str = malloc(999);
    if(strlen(find) < 2) return str;
    
}

void char__replace(const char *str, const char *find_char, const char *replacement, const char *dest) {

}
#endif