//
// Created by 3G on 03/07/2025.
//

#include "fileOps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char AuthorArr [50][150];
char TitleArr [50][150];
char TypeArr [50][150];
int YearArr [50];
FILE *ptr;
void trim(char *str) {
    int i;
    for (i = strlen(str) - 1; i >= 0 && (str[i] == ',' || str[i] == '}' || str[i] == '\n' || str[i] == ' '); i--) {
        str[i] = '\0';
    }
    if (str[0] == '{') memmove(str, str + 1, strlen(str));
}

void ReadData(char *location) {
    int t = 0;
    char line[1024];
    char key[50], value[1024];
    char src[100] = "";
    strcat(src, location);

    ptr = fopen(src, "r");
    if (ptr == NULL) {
        printf("Error Reading the data from file!\n");
        exit(1);
    } else {
        printf("Data Successfully loaded, press any key to continue!\n");
        getchar();
    }

    while (fgets(line, sizeof(line), ptr)) {
        if (strncmp(line, "@", 1) == 0) {
            sscanf(line, "@%[^'{']", TypeArr[t]); // extract type
        } else if (strstr(line, "title") != NULL) {
            sscanf(line, "%*[^=]= {%[^}]", value);
            trim(value);
            strncpy(TitleArr[t], value, 50);
        } else if (strstr(line, "author") != NULL) {
            sscanf(line, "%*[^=]= {%[^}]", value);
            trim(value);
            strncpy(AuthorArr[t], value, 50);
        } else if (strstr(line, "year") != NULL) {
            sscanf(line, "%*[^=]= {%[^}]", value);
            trim(value);
            YearArr[t] = atoi(value);
        } else if (line[0] == '}') {
            t++; // End of entry
        }
    }

    fclose(ptr);

    // print the result
    for (int i = 0; i < t; i++) {
        printf("---- Entry %d ----\n", i + 1);
        printf("Type: %s\n", TypeArr[i]);
        printf("Title: %s\n", TitleArr[i]);
        printf("Author: %s\n", AuthorArr[i]);
        printf("Year: %d\n", YearArr[i]);
    }
}