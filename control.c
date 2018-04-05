#include <stdio.h>
#include <string.h>
#include "control.h"
#include "cJSON.h"
#include "view.h"
//const char *DB_All_books = "DBAllBooks.txt";
//const char* DB_All_members = "DBmembers.txt";
const char* DB_Books = "DB_Books.json";
const char* DB_Members = "DB_Members.json";
const char* DB_Borrowed_Books = "DB_BorrowedBooks.json";

//Initializing Book Array
void control_initialize_all_books()
{
    currentNumberOfBooks = 0;
    FILE* DB_all_books_Json_file = fopen(DB_Books,"r");
    if(DB_all_books_Json_file == NULL)
    {
        clear_console();
        printf("File Not Found! ");
        console_sleep(3);
        view_fatal_error();
        return;
    }
    int lines = control_count_number_of_lines(DB_all_books_Json_file);
    lines/=11;
    //printf("LINES::::::%d *******\n",lines);
    allBooks = (Book*) malloc(sizeof(Book)*lines);
    Book*  Books = (Book*) malloc(sizeof(Book)*lines);
    Books = allBooks;
    char* title = (char*)malloc(128);
    char* author = (char*)malloc(128);
    char* publisher = (char*)malloc(128);
    char*ISBN = (char*)malloc(16);
    char* date = (char*)malloc(16);
    int numberOfCopies;
    int availableNumberOfCopies;
    int numberOfTimesBorrowed;
    char*category = (char*)malloc(128);
    int j = 0;
    rewind(DB_all_books_Json_file);
    char* filestring  = malloc(128*lines*11);
    strcpy(filestring,"");
    char* buffer = malloc(128);
    while(!feof(DB_all_books_Json_file))
    {
        fgets(buffer,128,DB_all_books_Json_file);
        strcat(filestring , buffer);
    }
    cJSON *root = cJSON_Parse(filestring);
    cJSON * b = cJSON_GetObjectItemCaseSensitive(root,"book");

    while(b)
    {

        cJSON *title_json = cJSON_GetObjectItemCaseSensitive(b, "title");
        cJSON *author_json = cJSON_GetObjectItemCaseSensitive(b, "author");
        cJSON *publisher_json = cJSON_GetObjectItemCaseSensitive(b, "publisher");
        cJSON *ISBN_json = cJSON_GetObjectItemCaseSensitive(b, "ISBN");
        cJSON *date_json = cJSON_GetObjectItemCaseSensitive(b, "date");
        cJSON *numberOfCopies_json = cJSON_GetObjectItemCaseSensitive(b, "numberOfCopies");
        cJSON *numberOfTimesBorrowed_json = cJSON_GetObjectItemCaseSensitive(b, "numberOfTimesBorrowed");
        cJSON *availableNumberOfCopies_json = cJSON_GetObjectItemCaseSensitive(b, "availableCopies");
        cJSON *category_json = cJSON_GetObjectItemCaseSensitive(b, "category");
        title = title_json->valuestring;
        author = author_json->valuestring;
        publisher= publisher_json->valuestring;
        ISBN = ISBN_json->valuestring;
        date = date_json->valuestring;
        numberOfCopies = numberOfCopies_json->valueint;
        availableNumberOfCopies = availableNumberOfCopies_json->valueint;
        numberOfTimesBorrowed = numberOfTimesBorrowed_json->valueint;
        category = category_json->valuestring;
        // printf("%s ,%s ,%s ,%s ,%s ,%d ,%d ,%s  \n",title,author,publisher,ISBN,date,numberOfCopies,availableNumberOfCopies,category);
        Date* dat = control_get_date_format_from_string(date);
        *Books = *init_book(title,author,publisher,ISBN,dat,numberOfCopies,numberOfTimesBorrowed,availableNumberOfCopies,category);
        Books++;
        j++;
        b = b->next;
    }

    /*while(l--)
    {
        char *buffer = (char*)malloc(4096);
        fgets(buffer,4096,DB_all_books_file);
        // puts(buffer);
        if(strlen(buffer)>8)
        {
            sscanf(buffer,"%[^,]%*c%[^,]%*c%[^,]%*c%[^,]%*c%[^,]%*c%d,%d,%[^,\n]%*c",title,author,publisher,ISBN,date,&numberOfCopies,&availableNumberOfCopies,category);
            //printf("%s ,%s ,%s ,%s ,%s ,%d ,%d ,%s  current lines %d\n",title,author,publisher,ISBN,date,numberOfCopies,availableNumberOfCopies,category,l);
            //printf("%s ,%s ,%s ,%s ,%s ,%d ,%d ,%s  \n",title,author,publisher,ISBN,date,numberOfCopies,availableNumberOfCopies,category);
            Date* dat = control_get_date_format_from_string(date);
            *Books = *init_book(title,author,publisher,ISBN,dat,numberOfCopies,availableNumberOfCopies,category);
            //printf("%d\n",j);
            Books++;
            j++;
            free(buffer);

        }
        //printf("%s .. %s .... %s \n",allBooks[j-1].title,allBooks[j-1].author,allBooks[j-1].category);
    }*/
    currentNumberOfBooks =  j;
    free(title);
    free(author);
    free(publisher);
    free(ISBN);
    free(date);
    free(category);
    free(buffer);
    free(filestring);
    fclose(DB_all_books_Json_file);
    util_sort_books_number_of_times_borrowed();
}
//Book Constructor
Book* init_book(char* title,char* author,char* publisher
                ,char*ISBN, Date* date , int numberOfCopies,int numberOfTimesBorrowed
                ,int availableNumberOfCopies,char*category)
{
    //mallocations
    Book *initBook = (Book*)malloc(sizeof(Book));
    initBook->title = (char*)malloc(strlen(title)+1);
    initBook->author = (char*)malloc(strlen(author)+1);
    initBook->publisher = (char*)malloc(strlen(publisher)+1);
    initBook->category = (char*)malloc(strlen(category)+1);
//contructor things
    strcpy(initBook->title ,title);
    strcpy(initBook->author ,author);
    strcpy(initBook->publisher ,publisher);
    strcpy(initBook->ISBN,ISBN);
    initBook->publishDate = *date;
    initBook->numberOfCopies = numberOfCopies;
    initBook->currentAvailableCopies = availableNumberOfCopies;
    initBook->numberOfTimesBorrowed = numberOfTimesBorrowed;
    strcpy(initBook->category ,category);
    return initBook;
}
//Initializing Borrowed Books array
void control_initialize_all_borrowed_books()
{
    currentNumberOfBorrowedBooks = 0;
    FILE* DB_borrowed_books_file = fopen(DB_Borrowed_Books,"r");
    if(DB_borrowed_books_file == NULL)
    {
        clear_console();
        printf("File Not Found! ");
        console_sleep(3);
        view_fatal_error();
        return;
    }
    int lines = control_count_number_of_lines(DB_borrowed_books_file);
    lines/=7;
       // printf("Borrowed LINES::::::%d *******\n",lines);

    allBorrowedBooks  = (BorrowedBook*) malloc(sizeof(BorrowedBook)*lines);
    BorrowedBook* BorrowedB= (BorrowedBook*) malloc(sizeof(BorrowedBook)*lines);
    BorrowedB = allBorrowedBooks;
    int userID;
    char bookISBN[14];
    int l = lines;
    int j = 0;
    rewind(DB_borrowed_books_file);
    char *  filestring = malloc(7*lines*128);
    strcpy(filestring,"");
    char * buffer =  malloc(128);
    while(!feof(DB_borrowed_books_file))
    {
        fgets(buffer  ,128, DB_borrowed_books_file);
        strcat(filestring , buffer);
    }
    cJSON* root = cJSON_Parse(filestring);
    cJSON * bb = cJSON_GetObjectItemCaseSensitive(root,"borrowedBook");
    while(bb)
    {
        cJSON *id_json = cJSON_GetObjectItemCaseSensitive(bb,"ID");
        cJSON *isbn_json = cJSON_GetObjectItemCaseSensitive(bb,"ISBN");
        cJSON *borrowdate_json = cJSON_GetObjectItemCaseSensitive(bb,"borrow date");
        cJSON *duedate_json= cJSON_GetObjectItemCaseSensitive(bb,"due date");
        cJSON *returndate_json= cJSON_GetObjectItemCaseSensitive(bb,"return date");
        userID = id_json->valueint;
        strcpy(bookISBN,isbn_json->valuestring);
        Date* borrowDate = control_get_date_format_from_string(borrowdate_json->valuestring);
        Date *dueDate = control_get_date_format_from_string(duedate_json->valuestring);
        Date *returnDate = control_get_date_format_from_string(returndate_json->valuestring);
        *BorrowedB= *init_borrowed_book(userID,bookISBN,borrowDate,dueDate,returnDate);
        BorrowedB++;
        j++;
        bb = bb->next;
    }
    currentNumberOfBorrowedBooks=  j;
    free(filestring);
    free(buffer);
    fclose(DB_borrowed_books_file);
}
BorrowedBook* init_borrowed_book(int userID,char* bookISBN,Date* borrowDate,Date* dueDate,Date* returnDate)
{
//memoryAllocations
    BorrowedBook* initBorrowedBook = (BorrowedBook*) malloc(sizeof(BorrowedBook));
//contructor things
    initBorrowedBook->userID = userID;
    strcpy(initBorrowedBook->bookISBN,bookISBN);
    initBorrowedBook->borrowDate = *borrowDate;
    initBorrowedBook->dueDate = *dueDate;
    if(returnDate!=NULL)initBorrowedBook->returnDate = *returnDate;
    return initBorrowedBook;
}

//Initializing Members Array
void control_initialize_all_members()
{
    currentNumberOfMembers = 0;
    FILE* DB_members_file = fopen(DB_Members,"r");
    if(DB_members_file == NULL)
    {
        clear_console();
        printf("File Not Found! ");
        console_sleep(3);
        view_fatal_error();
        return;
    }
    int lines = control_count_number_of_lines(DB_members_file);
    lines/=12;
    //printf("MEMBERS LINES::::::%d *******\n",lines);
    allMembers = (Member*) malloc(sizeof(Member)*lines);
    Member* Members = (Member*) malloc(sizeof(Member)*lines);
    Members = allMembers;
    char* firstName = (char*)malloc(128);
    char*  lastName = (char*) malloc(128);
    int ID;
    int buildingNumber;
    char* street = (char*) malloc(128);
    char* city = (char*) malloc(128);
    char* phoneNumber = (char*) malloc(12);
    int age;
    char* email = (char*) malloc(128);
    int l = lines;
    int j = 0;
    rewind(DB_members_file);
    char *  filestring = malloc(12*lines*128);
    strcpy(filestring,"");
    char * buffer =  malloc(128);
    while(!feof(DB_members_file))
    {
        fgets(buffer  ,128, DB_members_file);
        strcat(filestring , buffer);
    }
    cJSON* root = cJSON_Parse(filestring);
    cJSON * m = cJSON_GetObjectItemCaseSensitive(root,"member");
    while(m)
    {
        cJSON *lastName_json = cJSON_GetObjectItemCaseSensitive(m, "lastName");
        cJSON *firstName_json = cJSON_GetObjectItemCaseSensitive(m, "firstName");
        cJSON *ID_Json = cJSON_GetObjectItemCaseSensitive(m, "ID");
        cJSON *buildingNumber_json = cJSON_GetObjectItemCaseSensitive(m, "buildingNumber");
        cJSON *street_json= cJSON_GetObjectItemCaseSensitive(m, "street");
        cJSON *city_json= cJSON_GetObjectItemCaseSensitive(m, "city");
        cJSON *phoneNumber_json= cJSON_GetObjectItemCaseSensitive(m, "phoneNumber");
        cJSON *age_json = cJSON_GetObjectItemCaseSensitive(m, "age");
        cJSON *numberOfBooksBorrowed_json = cJSON_GetObjectItemCaseSensitive(m,"numberOfBooksBorrowed");
        cJSON *email_json= cJSON_GetObjectItemCaseSensitive(m, "email");
        lastName = lastName_json->valuestring;
        firstName = firstName_json->valuestring;
        ID = ID_Json->valueint;
        buildingNumber = buildingNumber_json->valueint;
        street = street_json->valuestring;
        city = city_json->valuestring;
        phoneNumber = phoneNumber_json->valuestring;
        age= age_json->valueint;
        email =  email_json->valuestring;
        *Members = *init_member(lastName,firstName,ID,buildingNumber,street,city,phoneNumber,age,numberOfBooksBorrowed_json->valueint,email);
        Members++;
        j++;
        m = m->next;
    }
    currentNumberOfMembers =  j;
    free(firstName);
    free(lastName);
    free(street);
    free(city);
    free(phoneNumber);
    free(email);
    free(filestring);
    free(buffer);
    fclose(DB_members_file);
    util_sort_members_by_id();
}
//Member constructor
Member* init_member(char* lastName,char* firstName,int ID,int buildingNumber,char*street
                    ,char*city,char* phoneNumber,int age,int numberOfBooksBorrowed,char* email)
{
//memoryAllocations
    Member* initMember = (Member*) malloc(sizeof(Member));
    initMember->memberName.lastName = (char*)malloc(strlen(lastName)+1);
    initMember->memberName.firstName = (char*)malloc(strlen(firstName)+1);
    initMember->memberAddress.street = (char*)malloc(strlen(street)+1);
    initMember->memberAddress.city = (char*)malloc(strlen(city)+1);
    initMember->email= (char*)malloc(strlen(email)+1);
//contructor things
    initMember->ID = ID;
    initMember->age=age;
    initMember->memberAddress.buildingNumber = buildingNumber;
    initMember->numberOfBooksBorrowed = numberOfBooksBorrowed;
    strcpy(initMember->memberName.lastName,lastName);
    strcpy(initMember->memberName.firstName,firstName);
    strcpy(initMember->memberAddress.street,street);
    strcpy(initMember->memberAddress.city,city);
    strcpy(initMember->email,email);
    strcpy(initMember->phoneNumber,phoneNumber);
    return initMember;
}


int control_insert_new_book()
{
    int i ;
    Book newBook = *view_get_book_info();
    Book* tempArray = (Book*)malloc(sizeof(Book)*currentNumberOfBooks);
    for(i = 0; i<currentNumberOfBooks; i++)
    {
        tempArray[i] = allBooks[i];
    }
    currentNumberOfBooks++;
    free(allBooks);
    allBooks = (Book*)malloc(sizeof(Book)*currentNumberOfBooks);
    for(i = 0; i<currentNumberOfBooks-1; i++)
    {
        allBooks[i]=tempArray[i];
    }
    allBooks[i] = newBook;
    //printf("%s \n%s \n%s ",allBooks[currentNumberOfBooks-1].title,allBooks[currentNumberOfBooks-1].author,allBooks[currentNumberOfBooks-1].category);
    free(tempArray);
    clear_console();
    printf("\nBook added , Dont forget to save :) \n");
    console_sleep(3);
    clear_console();
    view_book_management();
    return 1;
}

void control_delete_a_book_ISPN()
{
    int book_index = view_get_book_ISPN(0);
    if(~book_index)
    {
        currentNumberOfBooks--;
        int j =0,i;
        if(currentNumberOfBooks)
        {
            Book* tempArray = (Book*)malloc(sizeof(Book)*currentNumberOfBooks);
            for(i = 0; i<currentNumberOfBooks+1; i++)
            {
                if(i!=book_index)
                {
                    tempArray[j] = allBooks[i];
                    j++;
                }
            }
            free(allBooks);
            allBooks = (Book*)malloc(sizeof(Book)*currentNumberOfBooks);
            for(i = 0; i<currentNumberOfBooks; i++)
            {
                allBooks[i]=tempArray[i];
            }
            for(i = 0; i<currentNumberOfBooks; i++)
            {
                printf("%s\n",allBooks[i].title);
            }
        }
        else free(allBooks);
        view_main_menu();
    }
    else
    {
        view_fatal_error();
    }


}
//Registering Member
void  control_register_new_member()
{
    int i ;
    Member newMember = *view_get_member_info();
    Member* tempArray = (Member*)malloc(sizeof(Member)*currentNumberOfMembers);
    for(i = 0; i<currentNumberOfMembers; i++)
    {
        tempArray[i] = allMembers[i];
    }
    currentNumberOfMembers++;
    allMembers= (Member*)malloc(sizeof(Member)*currentNumberOfMembers);
    for(i = 0; i<currentNumberOfMembers-1; i++)
    {
        allMembers[i]=tempArray[i];
    }
    allMembers[i] = newMember;
    //printf("%s \n%s \n%s ",allBooks[currentNumberOfBooks-1].title,allBooks[currentNumberOfBooks-1].author,allBooks[currentNumberOfBooks-1].category);
    clear_console();
    printf("\nMember added Your ID : %d  , Dont forget to save :) \n",newMember.ID);
    util_sort_members_by_id();
    console_sleep(3);
    clear_console();
    view_member_management();
    return 1;

}
//removing member account by ID
void control_remove_account()
{
    int member_index = view_get_member_ID(control_remove_account);

    if(~member_index)
    {
        if(util_member_has_borrowed_book(allMembers[member_index].ID)){
            clear_console();
            printf("This User cannot be deleted, he didnt return a book yet  \n");
            console_sleep(5);
        }else{
        currentNumberOfMembers--;
        int j =0,i;
        if(currentNumberOfMembers)
        {
            Member* tempArray = (Member*)malloc(sizeof(Member)*currentNumberOfMembers);
            for(i = 0; i<currentNumberOfMembers+1; i++)
            {
                if(i!=member_index)
                {
                    tempArray[j] = allMembers[i];
                    j++;
                }
            }
            free(allMembers);
            allMembers = (Member*)malloc(sizeof(Member)*currentNumberOfMembers);
            for(i = 0; i<currentNumberOfMembers; i++)
            {
                allMembers[i]=tempArray[i];
            }
            for(i = 0; i<currentNumberOfMembers; i++)
            {
                printf("%d\n",allMembers[i].ID);
            }
        }

        else free(allMembers);
        }
        clear_console();
        util_sort_members_by_id();
        view_main_menu();
    }
    else
    {
        view_fatal_error();
    }


}
void control_add_new_copy_of_a_book(int n,int i)
{
    allBooks[i].currentAvailableCopies+=n;
    allBooks[i].numberOfCopies+=n;
}
void control_borrow_book()
{
    BorrowedBook bb = *view_get_borrowed_book_info();
    if(bb.userID == -1)
    {
        return;
    }
    int i ;
    BorrowedBook* tempArray = (BorrowedBook*)malloc(sizeof(BorrowedBook)*currentNumberOfBorrowedBooks);
    for(i = 0; i<currentNumberOfBorrowedBooks; i++)
    {
        tempArray[i] = allBorrowedBooks[i];
    }
    currentNumberOfBorrowedBooks++;

    free(allBorrowedBooks);
    allBorrowedBooks = (BorrowedBook*)malloc(sizeof(BorrowedBook)*currentNumberOfBorrowedBooks);
    for(i = 0; i<currentNumberOfBorrowedBooks-1; i++)
    {
        allBorrowedBooks[i]=tempArray[i];
    }
    allBorrowedBooks[i] = bb;
    free(tempArray);
    clear_console();
    printf("\nBook borrowed Duedate : %s , Dont forget to save :) \n",util_get_date_format_from_date_object(&bb.dueDate));
    console_sleep(4);
    clear_console();
    util_sort_books_number_of_times_borrowed();
    view_borrow_management();
    return ;
}
void control_return_book()
{
    int borrowed_book_index = view_get_borrowed_book_index();


    if(~borrowed_book_index)
    {   Date *rd = malloc(sizeof(Date));
        rd = util_get_current_OS_date();
        allBorrowedBooks[borrowed_book_index].returnDate =*rd;
    }
    else
    {
        view_fatal_error();
        return;
    }
    int cmpKey = util_comp_dates(allBorrowedBooks[borrowed_book_index].dueDate,allBorrowedBooks[borrowed_book_index].returnDate);
    printf("Book returned!");
    if(~cmpKey){
    printf("  Your are on time ");
    }else if(cmpKey==-1){
    printf("  Your are Late ");
    }
    console_sleep(5);
    clear_console();
    view_main_menu();
}
void control_get_overdue_books()
{
    view_print_overdue_books();
}
void control_get_most_popular_books()
{
    view_print_most_popular_books();
}
void control_save_changes()
{
    FILE* DB_Book_json_file =  fopen(DB_Books,"w");
    if(DB_Book_json_file == NULL)
    {
        view_fatal_error();
    }
    int i;
    //printf("%d*********\n",currentNumberOfBooks);
    cJSON *root;
    root = cJSON_CreateObject();
    for(i = 0 ; i <currentNumberOfBooks; i++)
    {
        /* char *temp = (char*)malloc(4096);
         sprintf(temp,"%s,%s,%s,%s,%0d/%0d/%0d,%d,%d,%s\n",allBooks[i].title,allBooks[i].author
                 ,allBooks[i].publisher,allBooks[i].ISBN
                 ,allBooks[i].publishDate.day,allBooks[i].publishDate.month
                 ,allBooks[i].publishDate.year,allBooks[i].numberOfCopies
                 ,allBooks[i].currentAvailableCopies,allBooks[i].category);
         fprintf(DB_all_books_file,temp);
         free(temp);*/
        cJSON *b;
        cJSON_AddItemToObject(root, "book", b = cJSON_CreateObject());
        cJSON_AddStringToObject(b, "title", allBooks[i].title);
        cJSON_AddStringToObject(b, "author", allBooks[i].author);
        cJSON_AddStringToObject(b, "publisher",allBooks[i].publisher);
        cJSON_AddStringToObject(b, "ISBN",allBooks[i].ISBN);
        cJSON_AddStringToObject(b, "date" , util_get_date_format_from_date_object(&allBooks[i].publishDate));
        cJSON_AddNumberToObject(b , "numberOfCopies",allBooks[i].numberOfCopies);
        cJSON_AddNumberToObject(b , "numberOfTimesBorrowed",allBooks[i].numberOfTimesBorrowed);
        cJSON_AddNumberToObject(b , "availableCopies",allBooks[i].currentAvailableCopies);
        cJSON_AddStringToObject(b , "category",allBooks[i].category);
    }
    //puts(cJSON_Print(root));
    fprintf(DB_Book_json_file,cJSON_Print(root));
    fclose(DB_Book_json_file);
    cJSON_Delete(root);
    //Members things
    FILE* DB_members_file =  fopen(DB_Members,"w");
    if(DB_members_file== NULL)
    {
        view_fatal_error();
    }
    // printf("%d*********\n",currentNumberOfMembers);
    root = cJSON_CreateObject();
    for(i = 0 ; i <currentNumberOfMembers; i++)
    {
        /*char *temp = (char*)malloc(4096);
        sprintf(temp,"%s,%s,%d,%d,%s,%s,%s,%d,%s\n",allMembers[i].memberName.lastName,allMembers[i].memberName.firstName,
                allMembers[i].ID,allMembers[i].memberAddress.buildingNumber,allMembers[i].memberAddress.street,
                allMembers[i].memberAddress.city,allMembers[i].phoneNumber,allMembers[i].age,allMembers[i].email);
        fprintf(DB_members_file,temp);
        free(temp);*/
        cJSON *m;
        cJSON_AddItemToObject(root, "member", m = cJSON_CreateObject());
        cJSON_AddStringToObject(m, "lastName", allMembers[i].memberName.lastName);
        cJSON_AddStringToObject(m, "firstName", allMembers[i].memberName.firstName);
        cJSON_AddNumberToObject(m, "ID",allMembers[i].ID);
        cJSON_AddNumberToObject(m, "buildingNumber",allMembers[i].memberAddress.buildingNumber);
        cJSON_AddStringToObject(m, "street",allMembers[i].memberAddress.street);
        cJSON_AddStringToObject(m , "city",allMembers[i].memberAddress.city);
        cJSON_AddStringToObject(m , "phoneNumber",allMembers[i].phoneNumber);
        cJSON_AddNumberToObject(m , "age",allMembers[i].age);
        cJSON_AddNumberToObject(m, "numberOfBooksBorrowed" , allMembers[i].numberOfBooksBorrowed);
        cJSON_AddStringToObject(m , "email",allMembers[i].email);
    }
    fprintf(DB_members_file ,cJSON_Print(root));
    fclose(DB_members_file);
    cJSON_Delete(root);

    //Borrowing things Under construction :)
    FILE* DB_Borrowed_Books_file =  fopen(DB_Borrowed_Books,"w");
    if(DB_Borrowed_Books_file== NULL)
    {
        view_fatal_error();
    }
    root = cJSON_CreateObject();

    for(i = 0 ; i <currentNumberOfBorrowedBooks; i++)
    {
        cJSON *bb;
        cJSON_AddItemToObject(root, "borrowedBook", bb = cJSON_CreateObject());
        cJSON_AddNumberToObject(bb, "ID", allBorrowedBooks[i].userID);
        cJSON_AddStringToObject(bb, "ISBN",allBorrowedBooks[i].bookISBN);
        cJSON_AddStringToObject(bb, "borrow date" , util_get_date_format_from_date_object(&allBorrowedBooks[i].borrowDate));
        cJSON_AddStringToObject(bb, "due date" , util_get_date_format_from_date_object(&allBorrowedBooks[i].dueDate));
        cJSON_AddStringToObject(bb, "return date" , util_get_date_format_from_date_object(&allBorrowedBooks[i].returnDate));

    }
    fprintf(DB_Borrowed_Books_file ,cJSON_Print(root));
    fclose(DB_Borrowed_Books_file);
    cJSON_Delete(root);
    printf("\nSaved!");
    return;
}
int control_count_number_of_lines(FILE* f)
{
    int lines = 0;
    while(!feof(f))
    {
        char ch = fgetc(f);
        if(ch == '\n')
        {
            lines++;
        }
        if(lines == 0)lines=1;
    }
    return lines;
}
Date* control_get_date_format_from_string(char* dateSt)
{
    Date* dat = (Date*)malloc(sizeof(Date));
    sscanf(dateSt,"%hd/%hd/%hd",&dat->day,&dat->month,&dat->year);
//printf("%u/%u/%u\n",dat->day,dat->month,dat->year);
    return dat;
}

/* char temp[128];
     for(i=0 ; i<8 ; i++)
     {
         int z=0;
         c =fgetc(DB_all_books_file);
         while((c!=','&&c!='\n')&& !feof(DB_all_books_file))
         {
             temp[z]=c;
             z++;
             c =fgetc(DB_all_books_file);
         }
         temp[z]='\0';
         switch(i)
         {
         case 0 :
             strcpy(title,temp);
             break;
         case 1 :
             strcpy(author,temp);
             break;
         case 2 :
             strcpy(publisher,temp);
             break;
         case 3 :
             strcpy(ISBN,temp);
             break;
         case 4 :
             strcpy(date,temp);
             break;
         case 5 :
             numberOfCopies = to_int(temp,strlen(temp));
             break;
         case 6 :
             availableNumberOfCopies = to_int(temp,strlen(temp));
             break;
         case 7 :
             strcpy(category,temp);
             break;
         }
     }*/
