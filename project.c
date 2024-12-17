#include <stdio.h>
#include <string.h>
struct Book
{
    char title[50];
    char author[50];
    int quantity;
};
void add_book(struct Book books[], int *total_books)
{
    printf("\n---------------------------------------\n");
    printf("|          Add a New Book             |\n");
    printf("---------------------------------------\n");
    printf("Enter book title: ");
    scanf("%s", books[*total_books].title);
    printf("Enter author name: ");
    scanf("%s", books[*total_books].author);
    printf("Enter quantity: ");
    scanf("%d", &books[*total_books].quantity);
    (*total_books)++;
    printf("\nBook added successfully!\n");
    printf("---------------------------------------\n");
}
void search_book(struct Book books[], int total_books)
{
    char search_title[50];
    printf("\n---------------------------------------\n");
    printf("|          Search for a Book          |\n");
    printf("---------------------------------------\n");
    printf("Enter title to search: ");
    scanf("%s", search_title);

    for (int i = 0; i < total_books; i++)
    {
        if (strcmp(books[i].title, search_title) == 0)
        {
            printf("\n---------------------------------------\n");
            printf("| Book Found!                         |\n");
            printf("---------------------------------------\n");
            printf("| Title    | %s\n", books[i].title);
            printf("| Author   | %s\n", books[i].author);
            printf("| Quantity | %d\n", books[i].quantity);
            printf("---------------------------------------\n");
            return;
        }
    }
    printf("\nBook not found.\n");
    printf("---------------------------------------\n");
}
void display_books(struct Book books[], int total_books)
{
    if (total_books == 0)
    {
        printf("\n---------------------------------------\n");
        printf("| No books in the library.            |\n");
        printf("---------------------------------------\n");
        return;
    }
    printf("\n---------------------------------------\n");
    printf("|          Books in Library           |\n");
    printf("---------------------------------------\n");
    printf("| No | Title                    | Author                   | Quantity |\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < total_books; i++)
    {
        printf("| %-2d | %-24s | %-24s | %-8d |\n", i + 1, books[i].title, books[i].author, books[i].quantity);
    }
    printf("---------------------------------------\n");
}
void delete_book(struct Book books[], int *total_books)
{
    char delete_title[50];
    printf("\n---------------------------------------\n");
    printf("|          Delete a Book              |\n");
    printf("---------------------------------------\n");
    printf("Enter the title of the book to delete: ");
    scanf("%s", delete_title);
    for (int i = 0; i < *total_books; i++)
    {
        if (strcmp(books[i].title, delete_title) == 0)
        {
            for (int j = i; j < *total_books - 1; j++)
            {
                books[j] = books[j + 1];
            }
            (*total_books)--;
            printf("\nBook '%s' has been deleted.\n", delete_title);
            printf("---------------------------------------\n");
            return;
        }
    }
    printf("\nBook not found.\n");
    printf("---------------------------------------\n");
}
void update_book(struct Book books[], int total_books)
{
    char update_title[50];
    printf("\n---------------------------------------\n");
    printf("|          Update Book Info           |\n");
    printf("---------------------------------------\n");
    printf("Enter the title of the book to update: ");
    scanf("%s", update_title);

    for (int i = 0; i < total_books; i++)
    {
        if (strcmp(books[i].title, update_title) == 0)
        {
            printf("Enter new title: ");
            scanf("%s", books[i].title);
            printf("Enter new author: ");
            scanf("%s", books[i].author);
            printf("Enter new quantity: ");
            scanf("%d", &books[i].quantity);
            printf("\nBook information updated successfully.\n");
            printf("---------------------------------------\n");
            return;
        }
    }
    printf("\nBook not found.\n");
    printf("---------------------------------------\n");
}
void count_books(int total_books)
{
    printf("\n---------------------------------------\n");
    printf("|          Book Count                 |\n");
    printf("---------------------------------------\n");
    printf("| Total number of books: %d            |\n", total_books);
    printf("---------------------------------------\n");
}
void borrow_book(struct Book books[], int total_books)
{
    char borrow_title[50];
    printf("\n---------------------------------------\n");
    printf("|          Borrow a Book              |\n");
    printf("---------------------------------------\n");
    printf("Enter the title of the book to borrow: ");
    scanf("%s", borrow_title);

    for (int i = 0; i < total_books; i++)
    {
        if (strcmp(books[i].title, borrow_title) == 0)
        {
            if (books[i].quantity > 0)
            {
                books[i].quantity--;
                printf("\nYou have borrowed '%s'. Remaining copies: %d\n", books[i].title, books[i].quantity);
                printf("---------------------------------------\n");
            }
            else
            {
                printf("\nSorry, '%s' is out of stock.\n", books[i].title);
                printf("---------------------------------------\n");
            }
            return;
        }
    }
    printf("\nBook not found.\n");
    printf("---------------------------------------\n");
}
void restock_book(struct Book books[], int total_books)
{
    char restock_title[50];
    int add_quantity;
    printf("\n---------------------------------------\n");
    printf("|          Restock a Book             |\n");
    printf("---------------------------------------\n");
    printf("Enter the title of the book to restock: ");
    scanf("%s", restock_title);
    for (int i = 0; i < total_books; i++)
    {
        if (strcmp(books[i].title, restock_title) == 0)
        {
            printf("Enter the quantity to add: ");
            scanf("%d", &add_quantity);
            books[i].quantity += add_quantity;
            printf("\nBook '%s' has been restocked. New quantity: %d\n", books[i].title, books[i].quantity);
            printf("---------------------------------------\n");
            return;
        }
    }
    printf("\nBook not found.\n");
    printf("---------------------------------------\n");
}
int main()
{
    struct Book library[100];
    int total_books = 0;
    int choice = 0;
    while (choice != 9)
    {
        printf("\n---------------------------------------\n");
        printf("|          Library Menu               |\n");
        printf("---------------------------------------\n");
        printf("| 1 | Add Book                        |\n");
        printf("| 2 | Search Book                     |\n");
        printf("| 3 | Display Books                   |\n");
        printf("| 4 | Delete Book                     |\n");
        printf("| 5 | Update Book                     |\n");
        printf("| 6 | Count Books                     |\n");
        printf("| 7 | Borrow Book                     |\n");
        printf("| 8 | Restock Book                    |\n");
        printf("| 9 | Exit                            |\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_book(library, &total_books);
            break;
        case 2:
            search_book(library, total_books);
            break;
        case 3:
            display_books(library, total_books);
            break;
        case 4:
            delete_book(library, &total_books);
            break;
        case 5:
            update_book(library, total_books);
            break;
        case 6:
            count_books(total_books);
            break;
        case 7:
            borrow_book(library, total_books);
            break;
        case 8:
            restock_book(library, total_books);
            break;
        case 9:
            printf("\nExiting program.\n");
            printf("---------------------------------------\n");
            break;
        default:
            printf("\nInvalid choice\n");
            printf("---------------------------------------\n");
        }
    }
    return 0;
}