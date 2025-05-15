#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_IDNUMBER 10000
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_GENRE 50
#define MAX_DESC 255
#define MAX_PASSWORD 20
#define MAX_USERNAME 50

// Login_SignUp Panel
#define MAX_USERS 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50
#define FILENAME "users.txt"

#define MAX_BOOKS 100

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char datePublished[11];
    int pages;
    char genres[MAX_GENRE];
    char description[MAX_DESC];
    float price;
    int idNumber;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void updateBook();
void deleteBook();
void adminLogin();
void userMenu();
void adminMenu();
void signUp_logIn();
void signup();
void login();
void loadBooks();

const char *BOOKS_FILE = "books.txt";
const char *ADMIN_USERNAME = "admin";
const char *ADMIN_PASSWORD = "password";
int main() {
    int choice;

    while (1) {
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|\tLIBRARY MANAGEMENT SYSTEM\t|\n");
        printf("\t\t\t\t\t|\t    BY BEBOSO AND OMAS\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n\n\n");
        printf("\t\t\t\t\t\t   [1] ADMIN LOGIN\n");
        printf("\t\t\t\t\t\t   [2] USER MENU\n");
        printf("\t\t\t\t\t\t   [3] EXIT\n\n");
        printf("\t\t\t\t\t\t  Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                Sleep(500);
                printf("\n\n\t\t\t\t\t\t  Entering User Menu.....\n\n");
                Sleep(2500);
                signUp_logIn();
                break;
            case 3:
                exit(0);
            default:
                printf("\n\n\t\t\t\t\t\tINVALID CHOICE! PLEASE TRY AGAIN.\n");
        }
    }

    return 0;
}

void adminLogin() {
    system("cls");
    char password[MAX_PASSWORD];
    char username[MAX_USERNAME];

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t*\t\t\t*\n");
    printf("\t\t\t\t\t\t*\t  LOGIN  \t*\n");
    printf("\t\t\t\t\t\t*\t\t\t*\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\n\n\t\t\t\t\t\t ENTER ADMIN USERNAME: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("\n\t\t\t\t\t\t ENTER ADMIN PASSWORD: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    
    if (strcmp(password, ADMIN_PASSWORD) == 0 && strcmp(username, ADMIN_USERNAME) == 0) {
        printf("\n\n\t\t\t\t\t\tSuccessfully Login..... :)\n\n\n");
        Sleep(2000);
        adminMenu();
    } else {
        printf("\n\n\t\t\t\t\t  Incorrect Username or Password, Please try Again..... :)\n\n");
        Sleep(2000);
        adminLogin();
        system("cls");
    }
    
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void adminMenu() {
    system("cls");
    int choice;
    char exit;

    while (1) {
        printf(" ------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t*************************\n");
        printf("\t\t\t\t\t\t*\t\t\t*\n");
        printf("\t\t\t\t\t\t*\tADMIN MENU\t*\n");
        printf("\t\t\t\t\t\t*\t\t\t*\n");
        printf("\t\t\t\t\t\t*************************\n\n\n");
        printf("\t\t\t\t\t\t   [1] ADD BOOK\n");
        printf("\t\t\t\t\t\t   [2] DISPLAY BOOKS\n");
        printf("\t\t\t\t\t\t   [3] SEARCH BOOK\n");
        printf("\t\t\t\t\t\t   [4] UPDATE BOOK\n");
        printf("\t\t\t\t\t\t   [5] DELETE BOOK\n");
        printf("\t\t\t\t\t\t   [6] LOGOUT\n\n");
        printf("\t\t\t\t\t\t  Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                printf("\t\t\t\t\tAre You Sure You Want To Exit?:[Y/N]: ");
                scanf("%c", &exit);
                if (exit == 'y' || exit == 'Y') {
                    printf("\n\t\t\t\t\t\tExiting, Please Wait!   :)\n");
                    Sleep(3000);
                    system("cls");
                } else {
                    printf("\t\t\t\t\tInvalid!   :(\n");
                }
                return;
            default:
                printf("\t\t\t\t\t\tInvalid choice, Please try again!   :(\n");
                system("cls");
        }
    }
}

void signUp_logIn() {
    system("cls");
    int choice;
    while (1) {
        system("cls");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t*********************************************************\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\tSIGNUP OR LOGIN YOUR ACCOUNT\t\t*\n");
        printf("\t\t\t\t*\t\t\t[1]SIGN UP\t\t\t*\n");
        printf("\t\t\t\t*            \t\t\t\t\t\t*\n");
        printf("\t\t\t\t*            \t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t[2]LOGIN\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*********************************************************\n\n\n");
        printf("\t\t\t\t\t\t   Enter Your Choice: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            default:
                printf("\n\n\t\t\t\t\t\tInvalid Choice, Please try Again!   :(\n\n");
        }
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void signup() {
    system("cls");
    User user;
    char confirmPassword[PASSWORD_LENGTH];
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Sleep(1000);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t**********************");
    printf("\n\t\t\t\t\t\t*\tSIGN UP\t     *\n");
    printf("\t\t\t\t\t\t**********************\n");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR USERNAME: ");
    scanf("%s", user.username);
    printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD: ");
    scanf("%s", user.password);
    printf("\n\n\t\t\t\t\t\t CONFIRM YOUR PASSWORD: ");
    scanf("%s", confirmPassword);

    if (strcmp(user.password, confirmPassword) != 0) {
        Sleep(1000);
        printf("\n\n\t\t\t\t\t\tPassword Does Not Match. Sign up Failed!   :)");
        Sleep(2000);
        fclose(file);
        return;
    }

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "[USERNAME]            [PASSWORD]\n");
    fprintf(file, "%s              %s\n", user.username, user.password);
    fclose(file);
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t  Signup successfully!   :)\n\n\n\n");
    Sleep(300);
    printf("\t\t\t\t\t\t  Please wait!   :)\n\n");
    Sleep(500);
    login();
}

void login() {
    system("cls");
    User user;
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int found = 0;
    
    Sleep(1000);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t**********************");
    printf("\n\t\t\t\t\t\t*\tLOG IN\t     *\n");
    printf("\t\t\t\t\t\t**********************\n");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR USERNAME: ");
    scanf("%s", username);
    printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD: ");
    scanf("%s", password);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        Sleep(2000);
        printf("\n\n\t\t\t\t\t\t  Login successful!   :)\n\n\n\n");
        Sleep(300);
        printf("\t\t\t\t\t\t  Please wait!   :)\n\n");
        Sleep(2000);
        userMenu();
    } else {
        Sleep(2000);
        printf("\t\t\t\t\t\t  Invalid Username or Password, Please try Again!!!   :)\n");
        Sleep(1000);
    }
}

void userMenu() {
    system("cls");
    int choice;

    while (1) {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t*************************\n");
        printf("\t\t\t\t\t\t*\t\t\t*\n");
        printf("\t\t\t\t\t\t*\tUSER MENU\t*\n");
        printf("\t\t\t\t\t\t*\t\t\t*\n");
        printf("\t\t\t\t\t\t*************************\n\n\n");
        printf("\t\t\t\t\t\t   [1] SEARCH BOOKS\n");
        printf("\t\t\t\t\t\t   [2] DISPLAY ALL AVAILABLE BOOKS\n");
        printf("\t\t\t\t\t\t   [3] LOGOUT\n");
        printf("\n\t\t\t\t\t\t  Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");

        switch (choice) {
            case 1:
                searchBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                return;
            default:
                printf("\n\t\t\t\t\t   Invalid choice, Please try again!   :)\n");
        }
    }
}

void addBook() {
    system("cls");
    Book book;
    FILE *file = fopen(BOOKS_FILE, "a");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\t\t\t\t\t\t   ENTER BOOK TITLE: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = 0;

    printf("\t\t\t\t\t\t   ENTER BOOK AUTHOR: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0;

    printf("\t\t\t\t\t\t   ENTER DATE PUBLISHED (YYYY-MM-DD): ");
    fgets(book.datePublished, sizeof(book.datePublished), stdin);
    book.datePublished[strcspn(book.datePublished, "\n")] = 0;

    printf("\t\t\t\t\t\t   ENTER HOW MANY PAGES: ");
    scanf("%d", &book.pages);
    getchar();

    printf("\t\t\t\t\t\t   ENTER BOOK GENRES: ");
    fgets(book.genres, sizeof(book.genres), stdin);
    book.genres[strcspn(book.genres, "\n")] = 0;

    printf("\t\t\t\t\t\t   ENTER BOOK DESCRIPTION: ");
    fgets(book.description, sizeof(book.description), stdin);
    book.description[strcspn(book.description, "\n")] = 0;

    printf("\t\t\t\t\t\t   ENTER THE BOOK PRICE: ");
    scanf("%f", &book.price);
    getchar();
    
    book.idNumber = bookCount + 1;
    bookCount++;
    fprintf(file, "%d; %s; %s; %s; %d; %s; %s; %.2f\n", book.idNumber, book.title, book.author, 
            book.datePublished, book.pages, book.genres, book.description, book.price);

    fclose(file);
    printf("\n\t\t\t\t\t\t\n");
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t   Book added successfully!   :)\n\n\n");
    Sleep(850);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void displayBooks() {
    printf("\n\t\t\t\t\t  Please Wait!   :)\n\n");
    Sleep(1000);
    system("cls");
    Book book;
    FILE *file = fopen(BOOKS_FILE, "r");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    printf("\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t*\t\t\t    *");
    printf("\n\t\t\t\t\t\t*   LIST OF ALL THE BOOKS   *\n");
    printf("\t\t\t\t\t\t*\t\t\t    *\n");
    printf("\t\t\t\t\t\t*****************************\n\n\n");
    
    while (fscanf(file, "%d; %[^;]; %[^;]; %[^;]; %d; %[^;]; %[^;]; %f\n", 
                  &book.idNumber, book.title, book.author, book.datePublished, 
                  &book.pages, book.genres, book.description, &book.price) != EOF) {
        printf("\t  ID: %d\n", book.idNumber);
        printf("\t  TITLE: %s\n", book.title);
        printf("\t  AUTHOR: %s\n", book.author);
        printf("\t  DATE PUBLISHED: %s\n", book.datePublished);
        printf("\t  PAGES: %d\n", book.pages);
        printf("\t  GENRES: %s\n", book.genres);
        printf("\t  DESCRIPTION: %s\n", book.description);
        printf("\t  PRICE: Php%.2f\n\n\n", book.price);
    }

    fclose(file);
}

void searchBook() {
    system("cls");
    char title[MAX_TITLE];
    Book book;
    int found = 0;
    FILE *file = fopen(BOOKS_FILE, "r");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    displayBooks();

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\t\t\t\t\t  ENTER BOOK TITLE TO SEARCH: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    while (fscanf(file, "%d; %[^;]; %[^;]; %[^;]; %d; %[^;]; %[^;]; %f\n", 
                  &book.idNumber, book.title, book.author, book.datePublished, 
                  &book.pages, book.genres, book.description, &book.price) != EOF) {
        if (strcasecmp(book.title, title) == 0) {
            printf("\n\n\t\t\t\t\t\t\t  BOOK FOUND:\n");
            printf("\n\n\t\t\t\t\t\t   BOOK NUMBER: %d\n", book.idNumber);
            printf("\n\n\t\t\t\t\t\t   TITLE: %s\n", book.title);
            printf("\n\t\t\t\t\t\t   AUTHOR: %s\n", book.author);
            printf("\n\t\t\t\t\t\t   DATE PUBLISHED: %s\n", book.datePublished);
            printf("\n\t\t\t\t\t\t   PAGES: %d\n", book.pages);
            printf("\n\t\t\t\t\t\t   GENRES: %s\n", book.genres);
            printf("\n\t\t\t\t\t\t   DESCRIPTION: %s\n", book.description);
            printf("\n\t\t\t\t\t\t   PRICE: Php%.2f\n", book.price);
            printf("\n\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\n\t\t\t\t\t\t   Book not found   :(\n");
    }

    fclose(file);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void updateBook() {
    system("cls");
    
    char title[MAX_TITLE];
    Book book;
    int found = 0;
    FILE *file = fopen(BOOKS_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Error opening file!\n");
        return;
    }
    displayBooks();
    printf("\t\t   ENTER BOOK TITLE TO UPDATE: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    while (fscanf(file, "%d; %[^;]; %[^;]; %[^;]; %d; %[^;]; %[^;]; %f\n", 
                  &book.idNumber, book.title, book.author, book.datePublished, 
                  &book.pages, book.genres, book.description, &book.price) != EOF) {
        if (strcasecmp(book.title, title) == 0) {
            found = 1;
            printf("\n\n\t\t   UPDATING:\n\n");
            printf("\t\t   Enter new title (leave blank to keep current): ");
            char newTitle[MAX_TITLE];
            fgets(newTitle, sizeof(newTitle), stdin);
            newTitle[strcspn(newTitle, "\n")] = 0;
            if (strlen(newTitle) > 0) {
                strcpy(book.title, newTitle);
            }

            printf("\n\n\t\t   Enter new author (leave blank to keep current): ");
            char newAuthor[MAX_AUTHOR];
            fgets(newAuthor, sizeof(newAuthor), stdin);
            newAuthor[strcspn(newAuthor, "\n")] = 0;
            if (strlen(newAuthor) > 0) {
                strcpy(book.author, newAuthor);
            }

            printf("\n\n\t\t   Enter new date published (leave blank to keep current): ");
            char newDate[11];
            fgets(newDate, sizeof(newDate), stdin);
            newDate[strcspn(newDate, "\n")] = 0;
            if (strlen(newDate) > 0) {
                strcpy(book.datePublished, newDate);
            }

            printf("\n\n\t\t   Enter new number of pages (leave blank to keep current): ");
            char newPages[10];
            fgets(newPages, sizeof(newPages), stdin);
            if (strlen(newPages) > 0) {
                book.pages = atoi(newPages);
            }

            printf("\n\n\t\t   Enter new genres (leave blank to keep current): ");
            char newGenres[MAX_GENRE];
            fgets(newGenres, sizeof(newGenres), stdin);
            newGenres[strcspn(newGenres, "\n")] = 0;
            if (strlen(newGenres) > 0) {
                strcpy(book.genres, newGenres);
            }

            printf("\n\n\t\t   Enter new description (leave blank to keep current): ");
            char newDescription[MAX_DESC];
            fgets(newDescription, sizeof(newDescription), stdin);
            newDescription[strcspn(newDescription, "\n")] = 0;
            if (strlen(newDescription) > 0) {
                strcpy(book.description, newDescription);
            }

            printf("\n\n\t\t   Enter new price (leave blank to keep current): ");
            char newPrice[10];
            fgets(newPrice, sizeof(newPrice), stdin);
            if (strlen(newPrice) > 0) {
                book.price = atof(newPrice);
            }
        }
        fprintf(tempFile, "%d; %s; %s; %s; %d; %s; %s; %.2f\n", book.idNumber, book.title, book.author, 
                book.datePublished, book.pages, book.genres, book.description, book.price);
    }

    if (!found) {
        Sleep(2000);
        printf("\n\n\n\n\t\t\t\t\t   Book not found!   :( \n");
    } else {
        Sleep(2000);
        printf("\n\n\n\n\t\t\t\t\t   Book updated successfully!   :) \n");
    }

    fclose(file);
    fclose(tempFile);
    remove(BOOKS_FILE);
    rename("temp.txt", BOOKS_FILE);
}

void deleteBook() {
    char title[MAX_TITLE];
    Book book;
    int found = 0;
    FILE *file = fopen(BOOKS_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
 printf("Error opening file!\n");
        return;
    }
    
    displayBooks();
    
    printf("Enter book title to delete: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    while (fscanf(file, "%d; %[^;]; %[^;]; %[^;]; %d; %[^;]; %[^;]; %f\n", 
                  &book.idNumber, book.title, book.author, book.datePublished, 
                  &book.pages, book.genres, book.description, &book.price) != EOF) {
        if (strcasecmp(book.title, title) == 0) {
            found = 1;
            printf("Book deleted successfully!\n");
            continue;
        }
        fprintf(tempFile, "%d; %s; %s; %s; %d; %s; %s; %.2f\n", book.idNumber, book.title, book.author, 
                book.datePublished, book.pages, book.genres, book.description, book.price);
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
    fclose(tempFile);
    remove(BOOKS_FILE);
    rename("temp.txt", BOOKS_FILE);
}