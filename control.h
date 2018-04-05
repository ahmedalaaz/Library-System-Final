#include <stdio.h>
#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
//Structures

typedef struct
{
    short int day;
    short int month;
    short int year;
} Date;

typedef struct
{
    char*  title;
    char*  author;
    char*  publisher;
    char  ISBN[14];
    char* category;
    Date  publishDate;
    unsigned int  numberOfCopies;
    unsigned int  currentAvailableCopies;
    int numberOfTimesBorrowed;
}Book;

typedef struct
{
    char* firstName;
    char* lastName;
} Name;

typedef struct
{
    int buildingNumber;
    char* street;
    char* city;
} Address;

typedef struct
{
    Name memberName;
    int ID;
    Address memberAddress;
    char phoneNumber[12];
    int age;
    int numberOfBooksBorrowed;
    char* email;
} Member;

typedef struct
{
        int userID;
        char bookISBN[14];
        Date borrowDate;
        Date dueDate;
        Date returnDate;

} BorrowedBook;
//Global Variables
Book* allBooks;
int currentNumberOfBooks;
Member* allMembers;
int currentNumberOfMembers;
BorrowedBook *allBorrowedBooks;
int currentNumberOfBorrowedBooks;
//Book Management Functions :
int control_insert_new_book();
void control_add_new_copy_of_a_book(int , int);
void control_delete_a_book_ISPN();

//Member Management :
void control_register_new_member();
void control_remove_account();

//Borrowing System :
void control_borrow_book();
void control_return_book();

//Admin Actions :
void control_get_overdue_books();
void control_get_most_popular_books();
void control_save_changes();

//control functions
void control_initialize_all_books();
void control_initialize_all_members();
void control_initialize_all_borrowed_books();

int control_count_number_of_lines(FILE*);

Date* control_get_date_format_from_string(char*);

Member* init_member(char*,char*,int,int,char*,char*,char*,int,int,char*);
Book* init_book(char*,char*,char*,char*,Date*,int,int,int,char*);
BorrowedBook* init_borrowed_book(int,char*,Date*,Date*,Date*);
#endif // CONTROL_H_INCLUDED
