#include <stdio.h>
#include <string.h>

struct Book
{
    char name[50];
    char author[50];
    float price;
    char issueDate[50];
};

struct Library
{
    struct Book books[100];
    int numBooks;
};

// Function Prototypes
void show_Welcome();
void show_exit_Message();
void add_Book(struct Library *library);
void show_all_books(const struct Library *library);
void search_Book(const struct Library *library);
void delete_Book(struct Library *library);

int main()
{
    show_Welcome();
    int choice;
    struct Library library = {0};

    do
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_Book(&library);
            break;
        case 2:
            show_all_books(&library);
            break;
        case 3:
            search_Book(&library);
            break;
        case 4:
            delete_Book(&library);
            break;
        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    show_exit_Message();
    return 0;
}

// Functions

void show_Welcome()
{
    printf("******************************************************************************************\n");
    printf("******************************************************************************************\n");
    printf("************************                                         *************************\n");
    printf("************************         Welcome to EWU Library          *************************\n");
    printf("************************                                         *************************\n");
    printf("******************************************************************************************\n");
    printf("******************************************************************************************\n");
}

void show_exit_Message()
{
    printf("*******************************  ************************  *******************************\n");
    printf("*******************************  ************************  *******************************\n");
    printf("************************                                         *************************\n");
    printf("************************         Thanks For using EWU library    *************************\n");
    printf("************************                                         *************************\n");
    printf("*******************************  ************************  *******************************\n");
    printf("*******************************  ************************  *******************************\n");
}

void add_Book(struct Library *library)
{
    if (library->numBooks < 100)
    {
        struct Book newBook;

        printf("Enter book name: ");
        scanf(" %[^\n]s", newBook.name);

        printf("Enter author: ");
        scanf(" %[^\n]s", newBook.author);

        printf("Enter price: ");
        scanf("%f", &newBook.price);

        printf("Enter issue date: ");
        scanf(" %[^\n]s", newBook.issueDate);

        library->books[library->numBooks++] = newBook;

        printf("Book added successfully!\n");
    }
    else
    {
        printf("Library is full. Cannot add more books.\n");
    }
}

void show_all_books(const struct Library *library)
{
    printf("\nList of Books\n");
    printf("--------------\n");

    for (int i = 0; i < library->numBooks; ++i)
    {
        printf("Book %d\n", i + 1);
        printf("Name: %s\n", library->books[i].name);
        printf("Author: %s\n", library->books[i].author);
        printf("Price: %.2f\n", library->books[i].price);
        printf("Issue Date: %s\n", library->books[i].issueDate);
        printf("--------------\n");
    }

    if (library->numBooks == 0)
    {
        printf("No books in the library.\n");
    }
}

void search_Book(const struct Library *library)
{
    char searchTitle[50];
    printf("Enter the book name to search: ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    for (int i = 0; i < library->numBooks; i++)
    {
        if (strcmp(library->books[i].name, searchTitle) == 0)
        {
            printf("Book found!\n");
            printf("Name: %s\n", library->books[i].name);
            printf("Author: %s\n", library->books[i].author);
            printf("Price: %.2f\n", library->books[i].price);
            printf("Issue Date: %s\n", library->books[i].issueDate);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Book not found in the library.\n");
    }
}

void delete_Book(struct Library *library)
{
    char deleteTitle[50];
    printf("Enter the book name to delete: ");
    scanf(" %[^\n]s", deleteTitle);

    int found = 0;
    for (int i = 0; i < library->numBooks; i++)
    {
        if (strcmp(library->books[i].name, deleteTitle) == 0)
        {
            // Shift remaining elements to fill the gap
            for (int j = i; j < library->numBooks - 1; j++)
            {
                library->books[j] = library->books[j + 1];
            }
            (library->numBooks)--;
            found = 1;
            printf("Book deleted successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Book with title %s not found in the library.\n", deleteTitle);
    }
}
