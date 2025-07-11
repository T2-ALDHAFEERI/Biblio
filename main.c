#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOps.h"
#include "Function.h"
int main(void) {
    printf("Welcome to my Bibliography project!\n");
    ReadData("biblio.txt");
    int result = detect_duplicate();
    if (result==0)
        printf("No doblication was found in your data \n");
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
        int result = detect_duplicate();
        if (result==0)
            printf("No doblication was found in your data \n");

    }
    else if (userChoice == 8) {
        show_UWE_Harvard();
    }
    else if (userChoice == 9) {
        show_missing_info();
    }
    else if (userChoice == 10) {
        struct Entries newEntry;
        printf("Enter the new entry type \n");
        scanf("%s",newEntry.TypeArr);


        add_entries(newEntry);
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
int detect_duplicate() {

    int duplication_result=0;
    for (int line=0 ; line < occupied_entries-1 ; line ++) {
        for (int subline = line +1 ; subline < occupied_entries ; subline++) {
            if (strstr (entries[line].TypeArr ,  entries[subline].TypeArr )
                && strstr (entries[line].AuthorArr ,  entries[subline].AuthorArr )
                    && strstr (entries[line].TitleArr ,  entries[subline].TitleArr )) {
                printf("Duplicte was found here \n");
                printf("Info : \n %s ,\n %s ,\n %s ,\n %d \n \n",
entries[line].AuthorArr,entries[line].TypeArr ,entries[line].TitleArr ,entries[line].YearArr);
                duplication_result=1;
            }
        }
    }
return duplication_result;
}
void show_UWE_Harvard() {

}
void show_missing_info() {

 for (int line = 0 ; line < occupied_entries ; line++ ) {
     int missing_year=0;
     int missing_type=0;
     int missing_author=0;
     int missing_title=0;
     if (entries[line].YearArr == 0) {
         missing_year=1;
         printf("year is missing -");
     }
     if (strlen (entries[line].TypeArr)==0) {
         missing_type=1;
         printf("Type is missing -");
     }
     if (strlen (entries[line].TitleArr)==0) {
         missing_title=1;
         printf("Title is missing -");
     }
     if (strlen (entries[line].AuthorArr)==0) {
         missing_author=1;
         printf("Author is missing -");

     }
     if (missing_year == 1 || missing_author==1 || missing_title == 1 || missing_type==1) {
        printf("Info missing at entry number %d please check to complete \n",line);
     }

 }

}
void add_entries(struct Entries entry) {
    FILE *ptr;
    ptr = fopen("biblio.txt", "a");
    if (ptr == NULL) {
        printf("Error Opening the file!\n");
    }
    fprintf(ptr,"");

}