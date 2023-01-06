/**
 * lib-jsmin v1.4.19
 *
 * Copyright (C) 2022-2023 Cromite.
 * Released under the MIT license.
 * see https://opensource.org/licenses/MIT
 * 
 * Release-Date: 2023-1-6
 * Bug reports to <admin@cromite.net>
 */

static void erase(char* text, int start, int end) {
    while (text[start] != '\0') {
        text[start] = text[start+end];
        start++;
    }
}
static int match(char* string, int pos, char* sample) {
    int i = 0;
    while (sample[i] != '\0') {
        if (sample[i] != string[pos+i]) return 0; 
        i++;
    } return 1;
}

static int is_symbol(char target) {
    char symbol[] = " \n!\"%&'()-=^~|`[]{};+:*<>,.?/";
    int i = 0;
    while (symbol[i] != '\0') {
        if (symbol[i] == target) return 1; 
        i++;
    } return 0;
}

char *jsmin(char *code) {
    int i = 0;
    while (code[i] != '\0') {
        if (match(code,i,"//")) while (code[i]!='\n') erase(code, i, 1);
        else if (match(code,i,"/*")) {
            while (!match(code,i,"*/")) erase(code, i, 1);
            erase(code, i, 2);
        }
        else if (code[i] == '"') {
            do i++;
            while (!(
                code[i] == '"' && 
                code[i-1] != '\\'
            ));
            i++;
            if (code[i]== ' ' && (
                is_symbol(code[i-1]) ||
                is_symbol(code[i+1])
            )) erase(code, i, 1);
        }
        else if (code[i] == '\'') {
            do i++;
            while (!(
                code[i] == '\'' &&
                code[i-1] != '\\'
            ));
            i++;
            if (code[i]== ' ' && (
                is_symbol(code[i-1]) ||
                is_symbol(code[i+1])
            )) erase(code, i, 1);
        }
        else if (
            code[i+1]== ' ' && (
                is_symbol(code[i]) ||
                is_symbol(code[i+2])
            )
        ) erase(code, i+1, 1);
        else if (code[i]== '\n') code[i] = ';';
        else if (code[i] == ';' && (
            is_symbol(code[i+1]) ||
            i == 0 || (
                is_symbol(code[i-1]) &&
                    code[i-1] != '"' &&
                    code[i-1] != '\'' &&
                    code[i-1] != '-' &&
                    code[i-1] != '+' &&
                    code[i-1] != '}' &&
                    code[i-1] != ']' &&
                    code[i-1] != ')'
                )
            )
        ) erase(code, i, 1);
        else i++;
    }
    if (code[i-1] == ';') erase(code, i-1, 1);
    return code;
}