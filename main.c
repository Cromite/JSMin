/**
 * jsmin v2.1.3
 *
 * Copyright (C) 2023 Cromite.
 * Released under the MIT license.
 * see https://opensource.org/licenses/MIT
 * 
 * Release-Date: 2023-1-6
 * Bug reports to <admin@cromite.net>
 */

#include <stdio.h>
#include "lib-jsmin.h"

static int equal(char *string, char *sample) {
    int i = 0;
    while (string[i] != '\0' || sample[i] != '\0') {
        if (string[i] != sample[i]) return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {

    char* input = NULL;
    char* output = NULL;
    int mode = 0;
    int overwrite = 0;

    // options
    if (argc > 0)
    for (int i = 1; i < argc; i++) {
        char *opt = *(argv + i);
        if (opt[0] == '-') {
            if (
                equal(opt, "-v") ||
                equal(opt, "--version")
            ) mode = 1;
            else if (
                equal(opt, "-h") ||
                equal(opt, "--help")
            ) mode = 2;
            else if (
                equal(opt, "-o") || 
                equal(opt, "--output")
            ) {
                i++;
                if (i < argc) {
                    if (*(argv + i)[0] == '-') {
                        printf("jsmin: argument to '%s' is missing\n", opt);
                        return 1;
                    } else output = *(argv + i);
                }
                else {
                    printf("jsmin: argument to '%s' is missing\n", opt);
                    return 1;
                }
            }
            else if (
                equal(opt, "-w") || 
                equal(opt, "--overwrite")
            ) overwrite = 1;
            else printf("jsmin: unknown option: '%s'\n", opt);
        } else input = opt;
    }

    switch (mode) {
        case 0:
            if (input != NULL) {
                if (overwrite) output = input;
                else if (output == NULL) {
                    char raw[30];
                    int i = 0;
                    while (input[i] != '\0' && !(
                        input[i] == '.' &&
                        input[i+1] == 'j' &&
                        input[i+2] == 's'
                    )) {raw[i] = input[i]; i++;}
                    char min[] = ".min.js";
                    int m = 0;
                    while (min[m] != '\0') {
                        raw[i+m] = min[m];
                        m++;
                    }
                    output = raw;
                }
                FILE *fp;

                // input file
                fp = fopen(input, "r");
                if( fp == NULL ) {
                    printf("jsmin: no such file: '%s'\n", input);
                    return 1;
                }
                char code[1048576];
                int i = 0;
                while((code[i] = fgetc(fp)) != EOF) i++;
                fclose(fp);
                code[i] = '\0';

                // output file
                fp = fopen(output, "w");
                fputs(jsmin(code), fp);
                fclose(fp);
            } else printf("jsmin: no input file\n");
            break;
        case 1: 
            printf(
                "jsmin 2.1.3\n"
                "Copyright (C) 2023 Cromite.\n"
                "Release-Date: 2023-1-6\n"
                "Bug reports to <admin@cromite.net>\n");
            break;
        case 2:
            printf(
                "Usage: jsmin <file> [options...]\n\n"
                "Options:\n"
                "  -o, --output <file>  write to <file> instead of writing in '...min.js'\n"
                "  -w, --overwrite      overwrite the file\n"
                "  -h, --help           get help for commands\n"
                "  -v, --version        show jsmin version\n\n");
    }
    return 0;
}
