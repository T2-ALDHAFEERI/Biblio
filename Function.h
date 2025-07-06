//
// Created by 3G on 30/06/2025.
//

#ifndef FUNCTION_H
#define FUNCTION_H

char userEntry[150];

int DisplayMenu();
void searchByAuthor(char *authorName);

void searchByTitle(char *title);
void searchBysingleYear(int year);
void seachByRangeOfYears(int year1 , int year2);
void displayTypes_count();
void showAuthors_alphabetically();
void detect_duplicate();
void show_UWE_Harvard();
void show_missing_info();
void add_entries();
#endif //FUNCTION_H
