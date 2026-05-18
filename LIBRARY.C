#include<stdio.h>
#include<string.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
    int quantity;
};

struct User
{
    char username[20];
    char password[20];
};

struct Book books[100];
struct User users[100];

int totalBooks = 0;
int totalUsers = 1;



// CREATE ACCOUNT
void createAccount()
{
    printf("\n===== CREATE ACCOUNT =====\n");

    printf("Enter Username: ");
    scanf("%s", users[totalUsers].username);

    printf("Enter Password: ");
    scanf("%s", users[totalUsers].password);

    totalUsers++;

    printf("\nAccount Created Successfully!\n");
}



// LOGIN FUNCTION
int login()
{
    char user[20];
    char pass[20];

    int i;

    printf("\n===== LOGIN =====\n");

    printf("Enter Username: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", pass);

    for(i = 0; i < totalUsers; i++)
    {
        if(strcmp(user, users[i].username) == 0 &&
           strcmp(pass, users[i].password) == 0)
        {
            return 1;
        }
    }

    return 0;
}



// ADD BOOK
void addBook()
{
    printf("\n===== ADD BOOK =====\n");

    printf("Enter Book ID: ");
    scanf("%d", &books[totalBooks].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[totalBooks].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[totalBooks].author);

    printf("Enter Quantity: ");
    scanf("%d", &books[totalBooks].quantity);

    totalBooks++;

    printf("\nBook Added Successfully!\n");
}



// DISPLAY BOOKS
void displayBooks()
{
    int i;

    if(totalBooks == 0)
    {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n===== BOOK LIST =====\n");

    for(i = 0; i < totalBooks; i++)
    {
        printf("\nBook %d\n", i + 1);

        printf("Book ID : %d\n", books[i].id);
        printf("Book Name : %s\n", books[i].name);
        printf("Author : %s\n", books[i].author);
        printf("Quantity : %d\n", books[i].quantity);
    }
}



// SEARCH BOOK
void searchBook()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for(i = 0; i < totalBooks; i++)
    {
        if(books[i].id == id)
        {
            printf("\nBook Found!\n");

            printf("Book ID : %d\n", books[i].id);
            printf("Book Name : %s\n", books[i].name);
            printf("Author : %s\n", books[i].author);
            printf("Quantity : %d\n", books[i].quantity);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nBook Not Found!\n");
    }
}



// ISSUE BOOK
void issueBook()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for(i = 0; i < totalBooks; i++)
    {
        if(books[i].id == id)
        {
            found = 1;

            if(books[i].quantity > 0)
            {
                books[i].quantity--;

                printf("\nBook Issued Successfully!\n");
            }
            else
            {
                printf("\nBook Not Available!\n");
            }
        }
    }

    if(found == 0)
    {
        printf("\nBook Not Found!\n");
    }
}



// RETURN BOOK
void returnBook()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for(i = 0; i < totalBooks; i++)
    {
        if(books[i].id == id)
        {
            books[i].quantity++;

            printf("\nBook Returned Successfully!\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nBook Not Found!\n");
    }
}



// DELETE BOOK
void deleteBook()
{
    int id;
    int i;
    int j;
    int found = 0;

    printf("\nEnter Book ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < totalBooks; i++)
    {
        if(books[i].id == id)
        {
            found = 1;

            for(j = i; j < totalBooks - 1; j++)
            {
                books[j] = books[j + 1];
            }

            totalBooks--;

            printf("\nBook Deleted Successfully!\n");
        }
    }

    if(found == 0)
    {
        printf("\nBook Not Found!\n");
    }
}



// MAIN FUNCTION
int main()
{
    int option;
    int choice;

    // DEFAULT ADMIN ACCOUNT
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "1234");

    while(1)
    {
        printf("\n\n===== LIBRARY MANAGEMENT SYSTEM =====\n");

        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("3. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:

                if(login())
                {
                    printf("\nLogin Successful!\n");

                    while(1)
                    {
                        printf("\n===== LIBRARY MENU =====\n");

                        printf("1. Add Book\n");
                        printf("2. Display Books\n");
                        printf("3. Search Book\n");
                        printf("4. Issue Book\n");
                        printf("5. Return Book\n");
                        printf("6. Delete Book\n");
                        printf("7. Logout\n");

                        printf("\nEnter Your Choice: ");
                        scanf("%d", &choice);

                        switch(choice)
                        {
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
                                issueBook();
                                break;

                            case 5:
                                returnBook();
                                break;

                            case 6:
                                deleteBook();
                                break;

                            case 7:
                                printf("\nLogged Out Successfully!\n");
                                break;

                            default:
                                printf("\nInvalid Choice!\n");
                                break;
                        }

                        if(choice == 7)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    printf("\nInvalid Username or Password!\n");
                }

                break;

            case 2:
                createAccount();
                break;

            case 3:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}