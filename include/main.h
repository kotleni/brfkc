#ifndef I_MAIN
#define I_MAIN
#endif

// c code snippets
#define PROG_START "\
    #include <stdio.h>\n\
    #include <stdlib.h>\n\
    #include <string.h>\n\
\n\
    int pointer = 0;\n\
    char mem[30000]; // TODO: fix unreasonable memory usage\n\
\n\
    void error(const char* text) {\n\
        puts(text);\n\
        exit(1);\n\
    }\n\
\n\
    void next() {\n\
        pointer += 1;\n\
\n\
        if(pointer >= sizeof(mem))\n\
            error(\"Pointer can't be > 30000\");\n\
    }\n\
\n\
    void prev() {\n\
        pointer -= 1;\n\
\n\
        if(pointer < 0)\n\
            error(\"Pointer can't be < 0\");\n\
    }\n\
\n\
    int main() {\n\
        memset(mem, '\\0', sizeof(mem));\n\
"
#define PROG_END "\nreturn 0;\n}"
#define PROG_NEXT "next();\n"
#define PROG_PREV "prev();\n"
#define PROG_ADD "mem[pointer]++;\n"
#define PROG_SUB "mem[pointer]--;\n"
#define PROG_OUT "putchar(mem[pointer]);\n"
#define PROG_IN "mem[pointer] = getchar();\n"
#define PROG_CBEGIN "while(mem[pointer]) {\n"
#define PROG_CEND "}\n"