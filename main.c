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

    }
    else {
        printf("invalid input (must be 1- \n");
    }
    return 0;
}

int DisplayMenu() {
    int userChoice;
    printf("Please choose one of the following \n");
    printf("1- Search based on Author name \n");
    printf("2- Search based on Title \n");

    scanf("%d" , &userChoice);
    return userChoice;
}

void searchByAuthor(char *authorName) {
    printf("You are searching for : %s" ,authorName);

}