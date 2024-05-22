#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char genre[50];
} Book;


typedef struct {
    char name[100];
    Book books[100];
    int book_count;
} Author;


Author authors[100];
Book library[100];
int numOfAuthors = 0;
int numOfBooks = 0;

void addHardcodedData()
{
    // Add hardcoded authors and their books
    // Author 1
    strcpy(authors[0].name, "George R.R. Martin");
    strcpy(authors[0].books[0].title, "A Game of Thrones");
    strcpy(authors[0].books[0].genre, "Fantasy");
    authors[0].book_count++;

    // Author 2
    strcpy(authors[1].name, "J.K. Rowling");
    strcpy(authors[1].books[0].title, "Harry Potter and the Sorcerer's Stone");
    strcpy(authors[1].books[0].genre, "Fantasy");
    authors[1].book_count++;

    // Author 3
    strcpy(authors[2].name, "J.R.R. Tolkien");
    strcpy(authors[2].books[0].title, "The Hobbit");
    strcpy(authors[2].books[0].genre, "Fantasy");
    strcpy(authors[2].books[1].title, "The Lord of the Rings");
    strcpy(authors[2].books[1].genre, "Fantasy");
    authors[2].book_count += 2;

    // Author 4
    strcpy(authors[3].name, "Stephen King");
    strcpy(authors[3].books[0].title, "The Shining");
    strcpy(authors[3].books[0].genre, "Horror");
    strcpy(authors[3].books[1].title, "It");
    strcpy(authors[3].books[1].genre, "Horror");
    authors[3].book_count += 2;

    // Author 5
    strcpy(authors[4].name, "Agatha Christie");
    strcpy(authors[4].books[0].title, "Murder on the Orient Express");
    strcpy(authors[4].books[0].genre, "Mystery");
    authors[4].book_count++;

    // Update the number of authors
    numOfAuthors = 5;
    numOfBooks = 5;
}
void printAuthors()
{
    printf("==============LIBRARY==============\n");
    for (int i = 0; i < numOfAuthors; i++)
    {
        printf("%-30s\n", authors[i].name);
        for (int j = 0; j < authors[i].book_count; j++)
        {
            printf("%-40s%-30s\n", authors[i].books[j].title, authors[i].books[j].genre);
        }
        printf("\n");
    }
}

void searchBook()
{
    printf("\nSearch for a Book: ");
    char searchTerm[100];
    getchar(); 
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    printf("\nResults:\n");

    int found = 0;
    for (int i = 0; i < numOfAuthors; i++)
    {
        for (int j = 0; j < authors[i].book_count; j++)
        {
            // Proverava da li postoji searchTerm kao substring u authors.[i].books[j].title
            if (strstr(authors[i].books[j].title, searchTerm) != NULL)
            {
                printf("%s by %s\n", authors[i].books[j].title, authors[i].name);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("No books found containing '%s'\n", searchTerm);
    }
}

void searchAuthor()
{
    printf("\nSearch for an Author: ");
    char searchTerm[100];
    getchar(); 
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    printf("\nResults:\n");

    int found = 0;
    for (int i = 0; i < numOfAuthors; i++)
    {
        if (strstr(authors[i].name, searchTerm) != NULL)
        {
            printf("%s\n", authors[i].name);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No authors found containing '%s'\n", searchTerm);
    }
}

void searchGenre() {
    printf("\nSearch for genre:");
    char searchTerm[20];
    int found = 0;

    getchar();
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    printf("\nResults:\n");
    
    for(int i = 0; i<numOfAuthors;i++) {
        for(int j = 0; j<authors[i].book_count;j++) {
            if(strstr(authors[i].books[j].genre, searchTerm) != NULL) {
                printf("%s\n", authors[i].books[j].title);
                found = 1;
            }
        }
    }
    if(!found) {
        printf("No %s books found.\n", searchTerm);
    }
}

void addBook() {
    printf("============ADDING BOOK============\n");

    char userTitle[100];
    char userAuthor[100];
    char userGenre[100];

    printf("\nTitle:");
    getchar();
    fgets(userTitle, sizeof(userTitle),stdin);
    userTitle[strcspn(userTitle,"\n")] = '\0';

    printf("\nGenre: ");
    fgets(userGenre, sizeof(userGenre), stdin);
    userGenre[strcspn(userGenre, "\n")] = '\0';


    printf("\nAuthor: ");
    fgets(userAuthor, sizeof(userAuthor), stdin);
    userAuthor[strcspn(userAuthor, "\n")] = '\0';

    // Check Author in authors
    int userFound = 0;
    for(int i = 0;i<numOfAuthors;i++) {
        if(strcmp(userAuthor, authors[i].name) == 0) {
            strcpy(authors[i].books[authors[i].book_count].title, userTitle);
            strcpy(authors[i].books[authors[i].book_count].genre, userGenre);
            strcpy(authors[i].books[authors[i].book_count].author, userAuthor);
            authors[i].book_count++;
            userFound = 1;
            break;
        }
    }
    if(userFound == 0) {
        printf("\nAuthor doesn't exist.");
        printf("\nDo you want to add this book and author to the Library?(Y/N)");
        char userInput[2];
        fgets(userInput, sizeof(userInput),stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        if(strcmp(userInput,"Y") == 0 || strcmp(userInput,"y") == 0) {
            strcpy(authors[numOfAuthors].name, userAuthor);
            strcpy(authors[numOfAuthors].books[authors[numOfAuthors].book_count].title, userTitle);
            strcpy(authors[numOfAuthors].books[authors[numOfAuthors].book_count].genre, userGenre);
            strcpy(authors[numOfAuthors].books[authors[numOfAuthors].book_count].author, userAuthor);
            authors[numOfAuthors].book_count++;
            numOfAuthors++;
            printf("\nBook and Author added successfuly!");
        }
        return;
    }

    numOfBooks++;
}

void addAuthor() {

    char author[100];
    printf("============ADDING AUTHOR============\n");
    printf("Author: ");
    getchar();
    fgets(author, sizeof(author),stdin);
    author[strcspn(author,"\n")] = '\0';

    for(int i = 0;i<numOfAuthors;i++) {
        if(strcmp(authors[i].name, author) == 0) {
            printf("! ! !   Author already exists   ! ! !\n");
            return;
        }
    }

    strcpy(authors[numOfAuthors].name, author);
    numOfAuthors++;
    printf("\nAuthor added successfuly\n");
}

void numOfBooksInLibrary() {
    printf("\nNumber of books in library is: %d", numOfBooks);
}

int main() {
    addHardcodedData();
    int userInput;
    int flag = 1;
    while(flag) {
        printf("====================================\n");
        printf("1. Search Book Title\n");
        printf("2. Search Author\n");
        printf("3. Search Genre\n");
        printf("4. Add Book to the Library\n");
        printf("5. Add Author to the Library\n");
        printf("6. Show all Authors\n");
        printf("7. Number of Books in Library\n");
        printf("8. Exit\n");
        printf("What do you want to do?:");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
            searchBook();
            printf("\n");
            break;
        case 2:
            searchAuthor();
            printf("\n");
            break;
        case 3:
            searchGenre();
            printf("\n");
            break;
        case 4:
            addBook();
            printf("\n");
            break;
        case 5:
            addAuthor();
            printf("\n");
            break;
        case 6:
            printAuthors();
            printf("\n");
            break;
        case 7:
            numOfBooksInLibrary();
            printf("\n");
            break;
        case 8:
            flag = 0;
            break;
        default:
            printf("Invalid input. Please choose a valid option.\n");
            break;
        }
    }

    return 0;
}