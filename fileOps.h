//
// Created by 3G on 03/07/2025.
//

#ifndef FILEOPS_H
#define FILEOPS_H

//structures
struct Entries {
    char AuthorArr [250];
    char TitleArr [250];
    char TypeArr [250];
    int YearArr  ;
    char issue[250];
    char publisher[250];
    char url[250];

};

extern struct Entries entries[50];
extern int occupied_entries;;
void ReadData(char *location);
void trim(char *str);
#endif //FILEOPS_H
