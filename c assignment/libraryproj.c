#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char title[50];
    char author[50];
    char status[20];
} Book;

void displaymenu();
void addbook();
void viewbooks();
void searchbook();
void issuebook();

int main() {
    displaymenu();
    return 0;
}

void displaymenu() {
    int choice;
    do {
        printf("\n--------LIBRARY MANAGEMENT SYSTEM--------\n");
        printf("1.Add new book\n");
        printf("2.View books\n");
        printf("3.Search for a book\n");
        printf("4.Borrow/return a book\n");
        printf("5.Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 :
            addbook();
            break;
            case 2 :
            viewbooks();
            break;
            case 3 :
            searchbook();
            break;
            case 4 :
            issuebook();
            break;
            case 5 :
            printf("exiting program!\n");
            break;
            default:
            printf("Invalid input.Try again\n");
        }
    } while (choice != 5);
}
void addbook(){
    FILE *fp ;
    Book b;
    fp = fopen("library.txt", "a");
    
    if(fp==NULL){
        printf("Error opening file\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    strcpy(b.status, "available");

    fprintf(fp, "%d,%s,%s,%s\n", b.id, b.title, b.author, b.status);

    fclose(fp);

    printf("Book added successfully!");
}

void viewbooks(){
    FILE *fp;
    Book b;
    fp=fopen("library.txt", "r");
   
    if(fp==NULL){
        printf("No books in library rn. Try again later XD");
        return;
    }
    printf("\n%-5s | %-30s | %-20s | %-15s\n", "ID", "Title", "Author", "Status");
    printf("-----------------------------------------------------------------\n");
    while(fscanf(fp, "%d,%49[^,],%49[^,],%14[^\n]\n", &b.id, b.title, b.author, b.status) != EOF){
         printf("\n%-5d | %-30s | %-20s | %-15s\n", b.id, b.title, b.author, b.status);
    }
    
    fclose(fp);
}

void searchbook(){
    FILE *fp;
    Book b;
    char input[50];
    int bookid;
    int found = 0;
   
    fp = fopen("library.txt", "r");
   
   if(fp==NULL){
        printf("No books in library yet.");
        return;
    }
    printf("\nEnter book id or title to search: ");
    getchar();
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if(sscanf(input, "%d", &bookid) == 1) {
        while(fscanf(fp, "%d,%49[^,],%49[^,],%14[^\n]", &b.id, b.title, b.author, b.status) != EOF){
            if(b.id==bookid){
                printf("\nfound:\nID:%d\nTitle:%s\nAuthor:%s\nStatus:%s\n", b.id, b.title, b.author, b.status);
                found = 1;
                break;

            }
        }
    }else {
        while(fscanf(fp, "%d,%49[^,],%49[^,],%14[^\n]", &b.id, b.title, b.author, b.status) != EOF){
            if(strstr(b.title, input) != NULL){
                printf("\nfound:\nID:%d\nTitle:%s\nAuthor:%s\nStatus:%s\n", b.id, b.title, b.author, b.status);
                found = 1;
                break;

            }
        }
    }
    if(!found){
        printf("No matching book found.");
    }
    
    fclose(fp);


}
void issuebook(){
    FILE *fp;
    Book books[100];
    int count = 0;
    int searchid;
    int found = 0;

    fp = fopen("library.txt", "r");
    if(fp == NULL){
        printf("no books in the library atm");
        return;
    }

    while(fscanf(fp, "%d,%49[^,],%49[^,],%14[^\n]\n", &books[count].id, books[count].title,books[count].author,books[count].status) != EOF){
        count++;
    }
    fclose(fp);

    printf("Enter Book ID to borrow/return: ");
    scanf("%d", &searchid);

    for(int i=0; i<count; i++){
        if(books[i].id == searchid){
            found = 1;

            if(strcmp(books[i].status, "available") == 0){
                strcpy(books[i].status, "borrowed");
                printf("Book -%s- issued successfully!\n", books[i].title);
            }else{
                strcpy(books[i].status, "available");
                printf("Book -%s- returned successfully!\n", books[i].title);
            }
            break;
        }
    }
    if(!found){
        printf("Book not available.\n");
        return;
    }

    fp=fopen("library.txt", "w");
    for(int i=0; i<count; i++){
        fprintf(fp, "%d,%s,%s,%s\n", books[i].id, books[i].title,books[i].author,books[i].status);
    }
    fclose(fp);
}