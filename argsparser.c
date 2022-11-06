/*
    argsparser.c - Custom command line args parser

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

#include <argsparser.h>

// try parse args, return result code
int parse_args(Args* args, int argc, char *argv[]) {
    if(argc >= 3) {
        // just get args via indexes
        args->input_path = argv[1];
        args->output_path = argv[2];

        return 0;
    }

    return 1;
}