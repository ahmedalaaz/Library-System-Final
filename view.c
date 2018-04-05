#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "view.h"
#include "control.h"
#include "utilities.h"

char *switcher;
char s;
void view_main_menu()
{

    printf(COLOR_BOLD_BLUE "\t\t\t**Welcome to our library**\n\n"COLOR_RESET);

    printf(COLOR_CYAN" (1) Book Management\n\n\
 (2) Member Management\n\n\
 (3) Borrow Management\n\n\
 (4) Administrative Management\n\n\
 (5) Print all books\n\n\
 (6) Print all Members\n\n\
 (7) Print all Borrowed Books\n\n\
 (8) Save changes\n\n\
 (9) Exit\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);
    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        //printf("%s2",switcher);
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_main_menu();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();

    switch(s)
    {
    case '1':
        view_book_management();
        break;
    case '2' :
        view_member_management();
        break;
    case '3' :
        view_borrow_management();
        break;
    case '4' :
        view_admin_actions();
        break;
    case '5' :
        view_print_all_book();
        break;
    case '6' :
        view_print_all_members();
        break;
    case '7' :
        view_print_all_borrowed_books();
        break;
    case '8' :
        control_save_changes();
        view_main_menu();
        break;

    case '9' :
        view_exit_page();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_main_menu();
    }

}

void view_book_management()
{
    printf(COLOR_BOLD_BLUE"\t\t\t**Book Management System**\n\n"COLOR_RESET);
    printf(COLOR_CYAN" (1) Insert a new book\n\n\
 (2) Search for a book\n\n\
 (3) Add new copy\n\n\
 (4) Delete a book\n\n\
 (5) Main Menu\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);

    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_book_management();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        control_insert_new_book();
        break;
    /*TODO: MultiSearch quering*/
    case '2' :
        view_get_book_search_query();
        break;
    case '3' :
        view_add_new_copy();
        break;
    case '4' :
        control_delete_a_book_ISPN();
        break;
    case '5' :
        view_main_menu();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_book_management();
    }

}

void view_member_management()
{

    printf(COLOR_BOLD_BLUE"\t\t\t**Member Management System**\n\n"COLOR_RESET);
    printf(COLOR_CYAN" (1) Registeration page\n\n\
 (2) Remove your account\n\n\
 (3) Main Menu\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);


    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_member_management();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        control_register_new_member();
        break;
    case '2' :
        control_remove_account();
        break;
    case '3' :
        view_main_menu();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_member_management();

    }
}
void view_borrow_management()
{

    printf(COLOR_BOLD_BLUE"\t\t\t**Borrowing Management System**\n\n"COLOR_RESET);
    printf(COLOR_CYAN" (1) Borrow a book\n\n\
 (2) Return a book\n\n\
 (3) Main Menu\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);
    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_borrow_management();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        control_borrow_book();
        break;
    case '2' :
        control_return_book();
        break;
    case '3' :
        view_main_menu();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_borrow_management();

    }
}

void view_admin_actions()
{
    printf(COLOR_BOLD_BLUE"\t\t\t**Administrative Actions**\n\n"COLOR_RESET);
    printf(COLOR_CYAN" (1) Overdue books\n\n\
 (2) Most popular books\n\n\
 (3) Main Menu\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);

    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_admin_actions();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        control_get_overdue_books();
        break;
    case '2' :
        control_get_most_popular_books();
        break;
    case '3' :
        view_main_menu();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_admin_actions();
    }
}
void view_exit_page()
{
 printf(COLOR_BOLD_BLUE"\t\t\t**Thanks for using our library!**\n\n"COLOR_RESET);
    printf(COLOR_CYAN" (1) Save and exit\n\n\
 (2) Exit without saving\n\n\
 (3) Main Menu\n\n\t\t\t"COLOR_RESET);
    printf(COLOR_DARK_GREEN"Enter your choice : "COLOR_RESET);

    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_exit_page();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        control_save_changes();
        exit(0);
        break;
    case '2' :
        exit(0);
        break;
    case '3' :
        view_main_menu();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_exit_page();
    }

}

Book* view_get_book_info()
{
    Book* tempBook = (Book*)malloc(sizeof(Book));
    char* title = (char*)malloc(128);
    char*  author = (char*) malloc(128);
    char*  publisher = (char*) malloc(128);
    char* category = (char*) malloc(128);
    char* date = (char*) malloc(128);
    char* ISBN = (char*)malloc(128);
    char* numberOfCopiesBeforeValidation = (char*) malloc(128);
    clear_console();
    fflush(stdin);
    printf("Could you provide the following information,\nBook Title : ");
    fgets(title,127,stdin);
    util_trim_white_space(title);
    /*Validate title :  no special characters*/
    if(!util_validate_no_special_characters(title))
    {

        clear_console();
        view_wrong_choice_retry(view_get_book_info,"Title's name cannot contain special characters ");
    }
    else
    {
        tempBook->title = (char*)malloc(strlen(title)+1);
        strcpy(tempBook->title,title);
        //  printf("%s",tempBook->title);
        fflush(stdin);
        printf("\nBook author : ");
        /*Validate author :  no special characters*/
        fgets(author,127,stdin);
        util_trim_white_space(author);
        if(!util_validate_no_special_characters(author))
        {

            clear_console();
            view_wrong_choice_retry(view_get_book_info,"Author's name cannot contain special characters ");
        }
        else
        {
            tempBook->author = (char*)malloc(strlen(author)+1);
            strcpy(tempBook->author,author);
            //printf("%s",tempBook->author);
            fflush(stdin);
            printf("\nBook publisher : ");
            /*Validate publisher :  no special characters*/
            fgets(publisher,127,stdin);
            util_trim_white_space(publisher);
            if(!util_validate_no_special_characters(publisher))
            {

                clear_console();
                view_wrong_choice_retry(view_get_book_info,"Publisher's name cannot contain special characters ");
            }
            else
            {
                tempBook->publisher = (char*)malloc(strlen(publisher)+1);
                strcpy(tempBook->publisher,publisher);
                //printf("%s",tempBook->publisher);
                fflush(stdin);
                printf("\nBook category : ");
                fgets(category,127,stdin);
                util_trim_white_space(category);
                if(!util_validate_only_alphabets(category))
                {

                    clear_console();
                    view_wrong_choice_retry(view_get_book_info,"Category's name has to consist only of alphabets ");
                }
                else
                {
                    tempBook->category = (char*)malloc(strlen(category)+1);
                    strcpy(tempBook->category,category);
                    // printf("%s",tempBook->category);
                    fflush(stdin);
                    printf("\nBook ISBN : ");
                    fgets(ISBN,127,stdin);
                    util_trim_white_space(ISBN);
                    //printf("%s\n",tempBook->ISBN);
                    /*TODO :: VALIDATE THE ISBN*/
                    if(!util_validate_ISBN(ISBN))
                    {
                        clear_console();
                        view_wrong_choice_retry(view_get_book_info,"Wrong ISBN format ");
                    }
                    else if(~util_check_for_ISBN_exist(ISBN))
                    {
                        clear_console();
                        view_wrong_choice_retry(view_get_book_info,"This ISBN already exists ");

                    }
                    else
                    {
                        strcpy(tempBook->ISBN,ISBN);
                        fflush(stdin);
                        printf("\nNumber of copies : (We get the first 9 characters to avoid overflow)");
                        /*Check for the OVERFLOW*/
                        fgets(numberOfCopiesBeforeValidation,9,stdin);
                        util_trim_white_space(numberOfCopiesBeforeValidation);
                        if(!util_check_only_numbers(numberOfCopiesBeforeValidation))
                        {
                            clear_console();
                            view_wrong_choice_retry(view_get_book_info,"Only Numbers allowed for this input ");
                        }
                        else
                        {
                            tempBook->numberOfCopies = to_int(numberOfCopiesBeforeValidation,strlen(numberOfCopiesBeforeValidation));
                            tempBook->currentAvailableCopies=tempBook->numberOfCopies;
                            // printf("%u\n",tempBook->numberOfCopies);
                            fflush(stdin);
                            printf("\nPublish Date :: DD/MM/YYYY,\nDate: ");
                            fgets(date,127,stdin);
                            util_trim_white_space(date);
                            if(!util_get_date_from_string(date)->day)
                            {
                                clear_console();
                                view_wrong_choice_retry(view_get_book_info,"Wrong date Format ");
                            }
                            else
                            {
                                puts(date);
                                Date *newDate = util_get_date_from_string(date);
                                puts("after");
                                tempBook->publishDate = *newDate;
                                /*TODO :: VALIDATE THE DATE*/
                                //view_print_date_formated(tempBook->publishDate);
                                free(author);
                                free(category);
                                free(publisher);
                                free(title);
                                free(numberOfCopiesBeforeValidation);
                                free(newDate);
                                free(date);
                                tempBook->numberOfTimesBorrowed = 0;
                                return tempBook;
                            }
                        }
                    }
                }
            }
        }
    }
}
int view_get_book_ISPN(int flag)
{
    clear_console();
    int i;
    if(!flag)
    for(i = 0 ; i<currentNumberOfBooks; i++)
    {
        printf("%d) Title : %s ** Author : %s ** ISBN : %s\n",i+1,allBooks[i].title
               ,allBooks[i].author,allBooks[i].ISBN);
    }
    if(flag)view_multi_search_borrow();
    printf("\n\nEnter the Book ISBN : ");
    char *ISBN = (char*) malloc(128);
    do
    {
        fflush(stdin);
        fgets(ISBN,127,stdin);
        util_trim_white_space(ISBN);
    }
    while((int)ISBN[0] == 0);
    if(!util_validate_ISBN(ISBN))
    {

        clear_console();
        view_wrong_choice_retry(view_get_book_ISPN,"Wrong ISBN format ");
    }
    else
    {
        int check = util_check_for_ISBN_exist(ISBN);
        if(~check)
        {
            return check;
        }
        view_wrong_choice_retry(view_get_book_ISPN,"This ISBN does not exist");
    }
}
void view_wrong_choice_retry(void foo(),char*message)
{
    clear_console();
    printf("%s \n (1) Retry\n (2) Main Menu \n Enter your choice : ",message );
    free(switcher);
    switcher = (char*)malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(2);
        clear_console();
        view_wrong_choice_retry(foo,message);
        view_main_menu();
    }
    else
    {
        s = switcher[0];
    }
    switch(s)
    {
    case '1' :
        foo();
        break;
    case '2' :
        clear_console();
        view_main_menu();
        break;
    default :
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice , Going to Main Menu\n" COLOR_RESET);
        console_sleep(2);
        clear_console();
        view_main_menu();
    }
    return -2;
}

Member* view_get_member_info()
{
    Member* tempMember = (Member*)malloc(sizeof(Member));
    char* firstName = (char*)malloc(128);
    char*  lastName = (char*) malloc(128);
    char*  ID = (char*) malloc(128);
    char* buildingNumber = (char*) malloc(128);
    char* street = (char*) malloc(128);
    char* city = (char*) malloc(128);
    char* phoneNumber = (char*) malloc(128);
    char* age = (char*) malloc(128);
    char* email = (char*) malloc(128);
    clear_console();
    printf("Could you provide the following information,\nFirst name : ");
    fflush(stdin);
    fgets(firstName,127,stdin);
    util_trim_white_space(firstName);
    /*Validate firstName :  no special characters and no spaces*/
    if(!util_validate_only_alphabets(firstName))
    {

        clear_console();
        view_wrong_choice_retry(view_get_member_info,"Name has to consist only of alphabets ");
    }
    else
    {
        tempMember->memberName.firstName = (char*)malloc(strlen(firstName)+1);
        strcpy(tempMember->memberName.firstName,firstName);
        // printf("%s",tempMember->memberName.firstName);
        printf("\nLast name : ");
        fflush(stdin);
        fgets(lastName,127,stdin);
        util_trim_white_space(lastName);

        /*Validate lastName :  no special characters and no spaces*/
        if(!util_validate_only_alphabets(lastName))
        {

            clear_console();
            view_wrong_choice_retry(view_get_member_info,"Name has to consist only of alphabets ");
        }
        else
        {
            tempMember->memberName.lastName = (char*)malloc(strlen(lastName)+1);
            strcpy(tempMember->memberName.lastName,lastName);
            // printf("%s",tempMember->memberName.lastName);
            printf("\nAddress , Building number : ");
            /*Validate Building number :  ONLY NUMBERS , NO SPACES*/
            gets(buildingNumber);
            /*CHECK FOR OVERFLOW*/
            if(!util_check_only_numbers(buildingNumber))
            {

                clear_console();
                view_wrong_choice_retry(view_get_member_info,"Only Numbers allowed for this input ");
            }
            else
            {
                tempMember->memberAddress.buildingNumber = to_int(buildingNumber,strlen(buildingNumber));
                // printf("%d",tempMember->memberAddress.buildingNumber);
                printf("\nStreet : ");
                /*Validate street : NO SPECIAL CHARACTERS EXCEPT FOR '.' ' '*/
                fflush(stdin);
                fgets(street,127,stdin);
                util_trim_white_space(street);
                tempMember->memberAddress.street = (char*)malloc(strlen(street)+1);
                strcpy(tempMember->memberAddress.street,street);
                //  printf("%s",tempMember->memberAddress.street);
                printf("\nCity : ");
                /*Validate city : ONLY ALPHA */
                fflush(stdin);
                fgets(city,127,stdin);
                util_trim_white_space(city);
                if(!util_validate_only_alphabets(city))
                {

                    clear_console();
                    view_wrong_choice_retry(view_get_member_info,"City's name has to consist only of alphabets ");
                }
                else
                {
                    tempMember->memberAddress.city = (char*)malloc(strlen(city)+1);
                    strcpy(tempMember->memberAddress.city,city);
                    // printf("%s",tempMember->memberAddress.city);
                    printf("\nPhone Number : ");
                    /*Validate phoneNUmber: ONLY numbers 11 char */
                    fflush(stdin);
                    fgets(phoneNumber,127,stdin);
                    util_trim_white_space(phoneNumber);
                    int lengthPhoneNumber = strlen(phoneNumber);
                    if(!util_check_only_numbers(phoneNumber) || lengthPhoneNumber != 11)
                    {

                        clear_console();
                        view_wrong_choice_retry(view_get_member_info,"Phone number has to consist only of numbers ,must be 11 digits ");
                    }
                    else
                    {
                        tempMember->phoneNumber;
                        strcpy(tempMember->phoneNumber,phoneNumber);
                        //printf("%s",tempMember->phoneNumber);
                        printf("\nAge : ");
                        /*Validate age : ONLY NUMBERS */
                        fflush(stdin);
                        fgets(age,127,stdin);
                        util_trim_white_space(age);
                        if(!util_check_only_numbers(age))
                        {
                            clear_console();
                            view_wrong_choice_retry(view_get_member_info,"Only Numbers allowed for this input ");
                        }
                        else
                        {
                            tempMember->age = to_int(age,strlen(age));
                            //printf("%d",tempMember->age);
                            printf("\nEmail ex: ahmed@domain.com : ");
                            /*Validate Email : Valid email address */
                            fflush(stdin);
                            fgets(email,127,stdin);
                            util_trim_white_space(email);
                            if(!util_valid_email_address(email))
                            {
                                clear_console();
                                view_wrong_choice_retry(view_get_member_info,"Wrong Email format ");
                            }
                            else
                            {
                                tempMember->email = (char*)malloc(strlen(email)+1);
                                strcpy(tempMember->email,email);
                                //  printf("%s",tempMember->email);
                                tempMember->ID = util_generate_ID();
                                tempMember->numberOfBooksBorrowed = 0;
                                free(firstName);
                                free(lastName);
                                free(ID );
                                free(buildingNumber);
                                free(street);
                                free(city);
                                free(phoneNumber);
                                free(age);
                                free(email);
                                return tempMember;
                            }
                        }
                    }
                }
            }
        }
    }
}
int view_get_member_ID(void foo())
{
    clear_console();
    printf("Enter the Member ID : ");
    int ID;
    char* ID_to_validate = malloc(128);
    fflush(stdin);
    fgets(ID_to_validate,127,stdin);
    util_trim_white_space(ID_to_validate);
    if(!util_check_only_numbers(ID_to_validate))
    {
        clear_console();
        view_wrong_choice_retry(foo, "Wrong ID format (Only numbers)");
    }
    else
    {
        ID = to_int(ID_to_validate,strlen(ID_to_validate));
        int check = util_check_for_ID_exist(ID);
        if(~check)
        {
            return check;
        }
        clear_console();
        view_wrong_choice_retry(foo,"This ID does not exist");
        return -1;
    }
}

void view_add_new_copy()
{
    int res = view_get_book_ISPN(0);
    if(res<0)view_fatal_error();
    char* nOfCopies = (char*)malloc(128);
    printf("Enter number of copies you want to add: \n");
    fflush(stdin);
    fgets(nOfCopies,8,stdin);
    fflush(stdin);
    util_trim_white_space(nOfCopies);
    if(!util_check_only_numbers(nOfCopies))
    {
        clear_console();
        view_wrong_choice_retry(view_get_member_info,"Only Numbers allowed for this input ");
    }
    else
    {
        /*validate nOfCopies only digits*/
        control_add_new_copy_of_a_book(to_int(nOfCopies,strlen(nOfCopies)),res);
        console_sleep(2);
        clear_console();
        view_main_menu();
    }
}

void view_print_date_formated(Date date)
{
    printf("Date : %02d/%02d/%04d\n",date.day,date.month,date.year);
}

int view_get_borrowed_book_index()
{
    int userIndex = view_get_member_ID(view_get_borrowed_book_index);
    int bookIndex;
    if(~userIndex)
    {
        bookIndex = view_get_book_ISPN(1);
    }
    if(!allMembers[userIndex].numberOfBooksBorrowed)
    {
        clear_console();
        printf("Member with ID : %d has no borrowed books\n",allMembers[userIndex].ID);
        console_sleep(2);
        clear_console();
        view_main_menu();
        return -1;
    }
    int i =util_check_for_borrowed_book(allMembers[userIndex].ID,allBooks[bookIndex].ISBN);
    if(~bookIndex && ~i)
    {
        allBooks[bookIndex].currentAvailableCopies++;
        allMembers[userIndex].numberOfBooksBorrowed--;
        return i;
    }
    else
    {
        clear_console();
        printf("Member with ID : %d has not borrowed book with ISBN %s\n",allMembers[userIndex].ID,allBooks[bookIndex].ISBN);
        console_sleep(2);
        clear_console();
        view_main_menu();
        return -1;
    }
}

BorrowedBook* view_get_borrowed_book_info()
{
    BorrowedBook* tempBorrowedBook = malloc(sizeof(BorrowedBook));
    tempBorrowedBook->userID = -1;
    int  userIndex = view_get_member_ID(control_borrow_book);
    int bookIndex;
    Date* borrowDate = malloc(sizeof(Date));
    Date* dueDate= malloc(sizeof(Date));
    Date* returnDate= malloc(sizeof(Date));
    returnDate->day =0;
    returnDate->month=0;
    returnDate->year = 0;
    if(~userIndex)
    {
        bookIndex = view_get_book_ISPN(1);
    }
    if(allBooks[bookIndex].currentAvailableCopies<=0)
    {
        printf("No current available copies of %s  with ISBN : %s , Borrowing process interrupted\n",allBooks[bookIndex].title,allBooks[bookIndex].ISBN);
        console_sleep(2);
        clear_console();
        view_main_menu();
    }
    else if(allMembers[userIndex].numberOfBooksBorrowed>=3)
    {
        clear_console();
        printf("Member %s %s with ID %d cannot borrow more books , Borrowing process interrupted\n",allMembers[userIndex].memberName.firstName,
               allMembers[userIndex].memberName.lastName, allMembers[userIndex].ID);
        console_sleep(2);
        clear_console();
        view_main_menu();
    }
    else if(~bookIndex && ~userIndex)
    {
        borrowDate = util_get_current_OS_date();
        *dueDate = util_add_14days_to_date(*borrowDate);
        printf("%s  \t %s  %d  %s \n",util_get_date_format_from_date_object(borrowDate),util_get_date_format_from_date_object(dueDate)
               , allMembers[userIndex].ID,allBooks[bookIndex].title);
        console_sleep(1);

        tempBorrowedBook->userID=allMembers[userIndex].ID;
        strcpy(tempBorrowedBook->bookISBN,allBooks[bookIndex].ISBN);
        tempBorrowedBook->borrowDate = *borrowDate;
        tempBorrowedBook->dueDate = *dueDate;
        tempBorrowedBook->returnDate= *returnDate;
        allBooks[bookIndex].currentAvailableCopies--;
        allBooks[bookIndex].numberOfTimesBorrowed++;
        allMembers[userIndex].numberOfBooksBorrowed++;
    }
    return tempBorrowedBook;

}
void view_fatal_error()
{
    clear_console();
    printf(COLOR_RED "\n\n\n\n\t\t\tSorry for the inconvenience , Going to Main Menu\n" COLOR_RESET);
    console_sleep(4);
    clear_console();
    view_main_menu();
}
void view_get_book_search_query()
{
    printf("\t\t\t Search for a Book\n\n\
 (1) Title\n\n\
 (2) Author\n\n\
 (3) Category\n\n\
 (4) ISBN\n\n\
 (5) Multiple Search \n\n\t\t\tEnter your choice : ");
    free(switcher);
    switcher = malloc(128);
    do
    {
        fflush(stdin);
        fgets(switcher,127,stdin);
        util_trim_white_space(switcher);
    }
    while((int)switcher[0] == 0);
    if(strlen(switcher)!=1)
    {
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tYou should enter only 1 character\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_borrow_management();
    }
    else
    {
        s = switcher[0];
    }
    clear_console();
    switch(s)
    {
    case '1' :
        view_search_for_a_book_title();
        break;
    case '2' :
        view_search_for_a_book_author();
        break;
    case '3' :
        view_search_for_a_book_category();
        break;
    case '4' :
        view_search_for_a_book_ISPN();
        break;
    case '5' :
        view_multi_search();
        break;
    default:
        clear_console();
        printf(COLOR_RED "\n\n\n\n\t\t\tWrong Choice\n" COLOR_RESET);
        console_sleep(4);
        clear_console();
        view_get_book_search_query();
    }

}
void view_search_for_a_book_title()
{
    printf("\tEnter the Title or part of it : ");
    char* title =  malloc(128);
    fflush(stdin);
    gets(title);
    util_to_lower_string(title);
    int i;
    printf("\n\n");

    for(i = 0 ; i<currentNumberOfBooks ; i++)
    {
        char* temp = malloc(strlen(allBooks[i].title)+1);
        strcpy(temp,allBooks[i].title);
        util_to_lower_string(temp);
        if(strstr(temp,title)!=NULL)
        {
            printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
        }
        free(temp);
    }
    printf("\n\nPress any key to continue...");
    if(getchar())
    {
        clear_console();
        view_book_management();
    }
}

void view_search_for_a_book_author()
{

    printf("\tEnter the Book's Author or part of it : ");
    char* author =  malloc(128);
    fflush(stdin);
    gets(author);
    util_to_lower_string(author);
    int i;
    printf("\n\n");
    for(i = 0 ; i<currentNumberOfBooks ; i++)
    {
        char* temp = malloc(strlen(allBooks[i].author)+1);
        strcpy(temp,allBooks[i].author);
        util_to_lower_string(temp);

        if(strstr(temp,author)!=NULL)
        {
            printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
        }
        free(temp);
    }
    printf("\n\nPress any key to continue...");
    if(getchar())
    {
        clear_console();
        view_book_management();
    }
}
void view_search_for_a_book_category()
{
    printf("\tEnter the Book's Category or part of it : ");
    char* category =  malloc(128);
    fflush(stdin);
    gets(category);
    util_to_lower_string(category);

    int i;
    printf("\n\n");
    for(i = 0 ; i<currentNumberOfBooks ; i++)
    {
        char* temp = malloc(strlen(allBooks[i].category)+1);
        strcpy(temp,allBooks[i].category);
        util_to_lower_string(temp);

        if(strstr(temp,category)!=NULL)
        {
            printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
        }
        free(temp);
    }
    printf("\n\nPress any key to continue...");
    if(getchar())
    {
        clear_console();
        view_book_management();
    }
}
void view_search_for_a_book_ISPN()
{
    printf("\tEnter the Book's ISBN : ");
    char* isbn =  malloc(128);
    fflush(stdin);
    gets(isbn);
    /*VALIDATE ISBN*/
    if(!util_validate_ISBN(isbn))
    {

        clear_console();
        view_wrong_choice_retry(view_search_for_a_book_ISPN,"Wrong ISBN format ");
    }
    else
    {
        int i;
        printf("\n\n");
        for(i = 0 ; i<currentNumberOfBooks ; i++)
        {
            if(!strcmp(allBooks[i].ISBN,isbn))
            {
                printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
            }
        }
        printf("\n\nPress any key to continue...");
        if(getchar())
        {
            clear_console();
            view_book_management();
        }
    }
}

void view_multi_search()
{
    int score = 0;
    printf("\tEnter the Title or part of it : ");
    char* title =  malloc(128);
    fflush(stdin);
    gets(title);
    util_to_lower_string(title);
    if(title[0]!=0)score++;
    printf("\tEnter the Book's Author or part of it : ");
    char* author =  malloc(128);
    fflush(stdin);
    gets(author);
    util_to_lower_string(author);

    if(author[0]!=0)score++;
    printf("\tEnter the Book's Category or part of it : ");
    char* category =  malloc(128);
    fflush(stdin);
    gets(category);
    util_to_lower_string(category);

    if(category[0]!=0)score++;
    printf("\tEnter the Book's ISBN : ");
    char* isbn =  malloc(128);
    fflush(stdin);
    gets(isbn);
    if(isbn[0]!=0)
    {
        /*Validate ISBN*/
        if(!util_validate_ISBN(isbn))
        {

            clear_console();

            view_wrong_choice_retry(view_multi_search,"Wrong ISBN format ");
        }
        else
        {
            score++;
        }
    }
    int i,bookScore;
    if(!score)score=-20;
    for( i = 0 ; i<currentNumberOfBooks ; i++)
    {
        bookScore =0 ;

        if(!strcmp(allBooks[i].ISBN,isbn))
        {
            bookScore++;
        }
        char* temp = malloc(strlen(allBooks[i].category)+1);
        strcpy(temp,allBooks[i].category);
        util_to_lower_string(temp);

        if(category[0]!=0 &&strstr(temp,category)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        temp = malloc(strlen(allBooks[i].author)+1);
        strcpy(temp,allBooks[i].author);
        util_to_lower_string(temp);

        if(author[0]!=0 &&strstr(temp,author)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        temp = malloc(strlen(allBooks[i].title)+1);
        strcpy(temp,allBooks[i].title);
        util_to_lower_string(temp);

        if(title[0]!=0 && strstr(temp,title)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        if(bookScore ==  score || score ==-20)printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category
                    ,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
    }

    printf("\n\nPress any key to continue...");
    if(getchar())
    {
        clear_console();
        view_book_management();
    }
}
void view_multi_search_borrow(){
    int score = 0;
    printf("\tEnter the Title or part of it : ");
    char* title =  malloc(128);
    fflush(stdin);
    gets(title);
    util_to_lower_string(title);
    if(title[0]!=0)score++;
    printf("\tEnter the Book's Author or part of it : ");
    char* author =  malloc(128);
    fflush(stdin);
    gets(author);
    util_to_lower_string(author);

    if(author[0]!=0)score++;
    printf("\tEnter the Book's Category or part of it : ");
    char* category =  malloc(128);
    fflush(stdin);
    gets(category);
    util_to_lower_string(category);

    if(category[0]!=0)score++;
    printf("\tEnter the Book's ISBN : ");
    char* isbn =  malloc(128);
    fflush(stdin);
    gets(isbn);
    if(isbn[0]!=0)
    {
        /*Validate ISBN*/
        if(!util_validate_ISBN(isbn))
        {

            clear_console();

            view_wrong_choice_retry(view_multi_search,"Wrong ISBN format ");
        }
        else
        {
            score++;
        }
    }
    int i,bookScore;
    if(!score)score=-20;
    for( i = 0 ; i<currentNumberOfBooks ; i++)
    {
        bookScore =0 ;

        if(!strcmp(allBooks[i].ISBN,isbn))
        {
            bookScore++;
        }
        char* temp = malloc(strlen(allBooks[i].category)+1);
        strcpy(temp,allBooks[i].category);
        util_to_lower_string(temp);

        if(category[0]!=0 &&strstr(temp,category)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        temp = malloc(strlen(allBooks[i].author)+1);
        strcpy(temp,allBooks[i].author);
        util_to_lower_string(temp);

        if(author[0]!=0 &&strstr(temp,author)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        temp = malloc(strlen(allBooks[i].title)+1);
        strcpy(temp,allBooks[i].title);
        util_to_lower_string(temp);

        if(title[0]!=0 && strstr(temp,title)!=NULL)
        {
            bookScore++;
        }
        free(temp);
        if(bookScore ==  score || score ==-20)printf(" Title : %s ,Category : %s ,ISBN: %s ,Available copies : %d \n",allBooks[i].title,allBooks[i].category
                    ,allBooks[i].ISBN,allBooks[i].currentAvailableCopies);
    }

}
void view_print_overdue_books()
{
    int i;
    for(i =0 ; i <currentNumberOfBorrowedBooks ; i++)
    {
        //Date d = *util_get_current_OS_date();
        //printf("%d %d %d \n",d.day,d.month,d.year);

        if(util_comp_dates(*util_get_current_OS_date(),allBorrowedBooks[i].dueDate) == 1)
        {
            int userIndex = util_check_for_ID_exist(allBorrowedBooks[i].userID);
            int bookIndex = util_check_for_ISBN_exist(allBorrowedBooks[i].bookISBN);
            printf("*******\nBook : %s with ISBN %s \nMember : %s %s with ID : %d  \nDue Date : %s\n",allBooks[bookIndex].title,allBooks[bookIndex].ISBN,
                   allMembers[userIndex].memberName.firstName,allMembers[userIndex].memberName.lastName,allMembers[userIndex].ID,
                   util_get_date_format_from_date_object(&allBorrowedBooks[i].dueDate));
        }
    }
    printf("\n\n\n press any key to continue.....");
    getchar();
    clear_console();
    view_admin_actions();
}

void view_print_most_popular_books()
{
    util_sort_books_number_of_times_borrowed();
    int i;
    for(i=0; i<currentNumberOfBooks; i++)
    {

        printf("%d) Title : %s , ISBN : %s  with number of Borrowing : %d\n",i+1,allBooks[i].title,
               allBooks[i].ISBN,allBooks[i].numberOfTimesBorrowed);
    }
    printf("\n\n\n press any key to continue.....");
    getchar();
    clear_console();
    view_admin_actions();

}

void view_print_all_members()
{
    int i;
    for(i = 0 ; i<currentNumberOfMembers ; i++)
    {
        printf("%d) First Name : %s ** Last Name : %s , ID : %d  \n",i+1,allMembers[i].memberName.firstName
               ,allMembers[i].memberName.lastName,allMembers[i].ID);
    }
    printf("\n\n\n press any key to continue.....");
    getchar();
    clear_console();
    view_main_menu();

}
void view_print_all_book()
{
    int i;
    for(i = 0 ; i<currentNumberOfBooks; i++)
    {
        printf("%d) Title : %s ** Author : %s ** ISBN : %s\n",i+1,allBooks[i].title
               ,allBooks[i].author,allBooks[i].ISBN);
    }
    printf("\n\n\n press any key to continue.....");
    getchar();
    clear_console();
    view_main_menu();

}
void view_print_all_borrowed_books()
{
    int i;
    for(i = 0 ; i<currentNumberOfBorrowedBooks; i++)
    {
        int userIndex = util_check_for_ID_exist(allBorrowedBooks[i].userID);
        int bookIndex = util_check_for_ISBN_exist(allBorrowedBooks[i].bookISBN);
        printf("*******\nBook : %s with ISBN %s \nMember : %s %s with ID : %d  \nDue Date : %s\n",allBooks[bookIndex].title,allBooks[bookIndex].ISBN,
               allMembers[userIndex].memberName.firstName,allMembers[userIndex].memberName.lastName,allMembers[userIndex].ID,
               util_get_date_format_from_date_object(&allBorrowedBooks[i].dueDate));
    }
    printf("\n\n\n press any key to continue.....");
    getchar();
    clear_console();
    view_main_menu();
}


void clear_console()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}
void console_sleep(int n)
{
#ifdef _WIN32
    Sleep(n*1000);
#else
#include <unistd.h>
    sleep(n);

#endif // _WIN32
}
