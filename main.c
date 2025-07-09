#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOps.h"
#include "Function.h"
int main(void) {
    printf("Welcome to my Bibliography project!\n");
    ReadData("biblio.txt");

    int userChoice = DisplayMenu();
    if (userChoice ==1) {
        printf("Please Enter Author name \n");
        scanf("%s", &userEntry);
        searchByAuthor( userEntry);
    }
    else if (userChoice == 2) {
        printf("Please Enter Title \n");
        scanf("%s", &userEntry);
        searchByTitle( userEntry);
    }


    else if (userChoice == 3) {
        int year;
        printf("Please Enter Year \n");
        scanf("%d", &year);
        searchBysingleYear( year);
    }
    else if (userChoice == 4) {
        int year;
        int lastYear;
        printf("Please Enter start year \n");
        scanf("%d", &year);
        printf("Please Enter last year \n");
        scanf("%d", &lastYear);
        seachByRangeOfYears( year ,lastYear);
    }
    else if (userChoice == 5) {
        displayTypes_count();
    }
    else if (userChoice == 6) {
        showAuthors_alphabetically();
    }
    else if (userChoice == 7) {
        detect_duplicate();
    }
    else if (userChoice == 8) {
        show_UWE_Harvard();
    }
    else if (userChoice == 9) {
        show_missing_info();
    }
    else if (userChoice == 10) {
        add_entries();
    }
    else if (userChoice == 11) {

    }

    else {
        printf("invalid input\n");
    }
    return 0;
}

int DisplayMenu() {
    int userChoice;
    printf("Please choose one of the following \n");
    printf("1- Search based on Author name \n");
    printf("2- Search based on Title \n");
    printf("3- Search based on Single year \n");
    printf("4- Search based on range of years \n");
    printf("5- Display different entry & its count \n");
    printf("6- Show authors alphabetically ordered \n");
    printf("7- Detect duplicate entries \n");
    printf("8- Show UWE Harvard style ref \n");
    printf("9- Show missing info \n");
    printf("10-Add new entry to list\n");
    printf("11-Exit\n");

    scanf("%d" , &userChoice);
    return userChoice;
}

void searchByAuthor(char *authorName) {
    for ( int line = 0 ; line < 50 ; line++ ) {
        if ( strstr (    entries[line].AuthorArr     ,  authorName   )  ) {
            printf("Info : \n %s ,\n %s ,\n %s ,\n %d \n \n",
                entries[line].AuthorArr,entries[line].TypeArr ,entries[line].TitleArr ,entries[line].YearArr);
        }
    }
}
void searchByTitle(char *title) {
    for ( int line = 0 ; line < 50 ; line++ ) {
        if ( strstr (    entries[line].TitleArr ,  title   )  ) {
            printf("Info : \n %s ,\n %s ,\n %s ,\n %d \n \n",
                entries[line].AuthorArr,entries[line].TypeArr ,entries[line].TitleArr ,entries[line].YearArr);
        }
    }
}
void searchBysingleYear(int year) {
    for ( int line = 0 ; line < 50 ; line++ ) {
        if (     entries[line].YearArr == year     ) {
            printf("Info : \n %s ,\n %s ,\n %s ,\n %d \n \n",
       entries[line].AuthorArr,entries[line].TypeArr ,entries[line].TitleArr ,entries[line].YearArr);
        }
        }
    }
void seachByRangeOfYears(int year1 , int year2) {
    for ( int line = 0 ; line < 50 ; line++ ) {
        if (    entries[line].YearArr >= year1  && entries[line].YearArr <= year2  ) {
            printf("Info : \n %s ,\n %s ,\n %s ,\n %d \n \n",
       entries[line].AuthorArr,entries[line].TypeArr ,entries[line].TitleArr ,entries[line].YearArr);

        }
    }
}
void displayTypes_count() {
    for ( int line = 0 ; line < 50 ; line++ ) {

        printf("%s \n" , entries[line].TypeArr);
    }
}
void showAuthors_alphabetically() {

}
void detect_duplicate() {

}
void show_UWE_Harvard() {

}
void show_missing_info() {

}
void add_entries() {

}