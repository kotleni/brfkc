#ifndef I_MAIN
#define I_MAIN
#endif

// c code snippets
#define PROG_HEAD "#include <stdio.h>\n#include <string.h>\n"
#define PROG_START "int main() {\nint i = 0;\nchar arr[30000];\nmemset(arr, '\\0', sizeof(arr));\n" // TODO: fix unreasonable memory usage
#define PROG_END "\nreturn 0;\n}"
#define PROG_NEXT "i++;\n"
#define PROG_PREV "i--;\n"
#define PROG_ADD "arr[i]++;\n"
#define PROG_SUB "arr[i]--;\n"
#define PROG_OUT "putchar(arr[i]);\n"
#define PROG_IN "arr[i] = getchar();\n"
#define PROG_CBEGIN "while(arr[i]) {\n"
#define PROG_CEND "}\n"