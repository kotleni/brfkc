/*
    main.c - Main file of brainfuck compiler

    Copyright (C) 2022 kotleni
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <argsparser.h>

int main(int argc, char *argv[]) {
    Args* args = (Args*) malloc(sizeof(Args));
    
    int result = parse_args(args, argc, argv);
    if(result != 0) {
        printf("Arguments error!");
        return result;
    }

    FILE* in_file = fopen(args->input_path, "r");
    FILE* out_file = fopen("output.c", "w+");

    printf("Generating sources...\n");

    // add head and start of c code
    fprintf(out_file, PROG_HEAD);
    fprintf(out_file, PROG_START);

    char ch;
    do {
        ch = fgetc(in_file);

        switch(ch) {
            case '>': // next cell
                fprintf(out_file, PROG_NEXT);
                break;
            case '<': // prev cell
                fprintf(out_file, PROG_PREV);
                break;
            case '+': // inc cell
                fprintf(out_file, PROG_ADD);
                break;
            case '-': // dec cell
                fprintf(out_file, PROG_SUB);
                break;
            case '.': // out cell value
                fprintf(out_file, PROG_OUT);
                break;
            case ',': // in value to cell
                fprintf(out_file, PROG_IN);
                break;
            case '[': // start cycle
                fprintf(out_file, PROG_CBEGIN);
                break;
            case ']': // end of cycle
                fprintf(out_file, PROG_CEND);
                break;
        }
    } while(ch != EOF);

    // add end of c code
    fprintf(out_file, PROG_END);

    fclose(in_file);
    fclose(out_file);

    printf("Compiling sources...\n");

    // make gcc command
    char* cmd = (char*) malloc(sizeof(char) * 32);
    sprintf(cmd, "gcc -o %s output.c", args->output_path);

    // invoke compiler
    int result = system(cmd);
    if(result != 0) {
        printf("Compiling error!\n");
        return result;
    }

    return 0;
}