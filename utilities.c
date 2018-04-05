#include "view.h"
#include "control.h"
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int util_validate_only_alphabets(char * input)
{
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        if(!isalpha((int) input[i])) return 0;
    }
    return 1;
}
int util_validate_no_special_characters(char* input){

for(unsigned int i = 0 ; input[i]!='\0' ; i++){
    if(!isalpha(input[i]) && !isdigit(input[i]) && input[i]!=' ')return 0 ;
    }
    return 1;
}

int util_validate_ISBN(char* ISBN)
{
    int cntDashes  = 0;
    int dashesIndexes[3];
    int i;
    int l = strlen(ISBN);
    if(l > 13)return 0;
    for(i = 0 ; i<l ; i ++)
    {
        if(ISBN[i]=='-')
        {
            dashesIndexes[cntDashes] =  i;
            cntDashes++;
        }
        if(!isdigit(ISBN[i])&& ISBN[i]!='-')return 0;
        if(cntDashes>3)return 0;
    }
    if(cntDashes<3)return 0;
    int diff=0;
    for( i = 0 ; i < 3; i++)
    {
        if(dashesIndexes[i] == 0 || dashesIndexes[i]==l-1)return 0 ;
    }
    if(dashesIndexes[1]-dashesIndexes[0]<=1 || dashesIndexes[2]-dashesIndexes[1]<=1 )return 0;

    return 1;

}
Date* util_get_current_OS_date()
{
    time_t timer;
    struct tm* tm_info;
    char day[3];
    char month[3];
    char year[5];
    time(&timer);
    tm_info = localtime(&timer);
    strftime(day, 3, "%d", tm_info);
    strftime(month, 3, "%m", tm_info);
    strftime(year, 5, "%Y", tm_info);
    Date* d = malloc(sizeof(Date));
    d->day = to_int(day,strlen(day));
    d->month= to_int(month,strlen(month));
    d->year= to_int(year,strlen(year));
    //printf("%d %d %d \t\t %s %s %s \n",d->day,d->month,d->year,day,month,year);
    return d;
}

Date* util_get_date_from_string(char* input)
{
    Date* date = malloc(sizeof(Date));
    date->day = 0 ;date->month=0;date->year=0;
    int slashesIndexes[2];
    int cntSlashes = 0;
    int i;
    int l = strlen(input);
    if(l > 10)return date;
     for(i = 0 ; i<l ; i ++)
    {
        if(input[i]=='/')
        {
            slashesIndexes[cntSlashes] =  i;
            cntSlashes++;
        }
        if(!isdigit(input[i])&& input[i]!='/')return date;
        //printf("f1\n");
        if(cntSlashes>2)return date;
        //printf("f2\n");
    }
    if(cntSlashes<2)return date;
  //  printf("f3\n");
    int diff=0;
    for( i = 0 ; i < 2; i++)
    {
        if(slashesIndexes[i] == 0 || slashesIndexes[i]==l-1)return date ;
    }
   // printf("f4\n");
    if(slashesIndexes[1]-slashesIndexes[0]<=1)return date;
    //printf("f5\n");
    int day, month, year;
    sscanf(input,"%u/%u/%u",&day,&month,&year);
    if(day <= 31 && day > 0) date->day = day;
    else date->day =0;
    if(month <= 12 && month >= 1) date->month = month;
   else date->day =0;
    if(year > 0) date->year = year;
    else date->day =0;
    if(util_comp_dates(*util_get_current_OS_date(),*date)==-1)date->day=0;
    return date;
}
Date util_add_14days_to_date(Date borrowDate)
{
    Date dueDate = borrowDate;
    if(31-dueDate.day >=14)
    {
        dueDate.day +=14;
        return dueDate;
    }
    dueDate.day  =  14 - (31-dueDate.day);
    if(dueDate.month != 12)
    {
        dueDate.month++;
        return dueDate;
    }
    dueDate.month = 1;
    dueDate.year++;
    return dueDate;
}

int util_check_for_ISBN_exist(char* ISBN)
{
    int i;
    for(i = 0 ; i < currentNumberOfBooks ; i++)
    {
        if(!strcmp(ISBN,allBooks[i].ISBN))return i;
    }
    return -1;
}

int util_check_for_ID_exist(int ID)
{
    int i;
    for(i = 0 ; i < currentNumberOfMembers; i++)
    {
        if(ID==allMembers[i].ID)return i;
    }
    return -1;

}

int util_check_for_borrowed_book(int ID,char* ISBN){
    int i;
    for(i = 0 ; i < currentNumberOfBorrowedBooks; i++)
    {
        if(ID==allBorrowedBooks[i].userID)if(!strcmp(allBorrowedBooks[i].bookISBN,ISBN))return i;
    }
    return -1;
}


int util_generate_ID()
{
    int i,id =1;
    for(i = 0 ; i <currentNumberOfMembers ; i++)
    {
        if(allMembers[i].ID!=id)return id;
            id++;

    }
    return id;
}

void util_sort_members_by_id()
{
    int flag,passes,i;
    Member temp ;
    for(passes = 0 ; passes < currentNumberOfMembers ; passes++)
    {
        flag =0;
        for(i =0 ; i<currentNumberOfMembers -1 ; i++)
        {
            if(allMembers[i].ID>allMembers[i+1].ID)
            {
                temp =allMembers[i];
                allMembers[i] = allMembers[i+1];
                allMembers[i+1]=temp;
                flag++;
            }
        }
        if(!flag)break;
    }
}

void util_sort_books_number_of_times_borrowed(){

  int flag,passes,i;
    Book temp ;
    for(passes = 0 ; passes < currentNumberOfBooks ; passes++)
    {
        flag =0;
        for(i =0 ; i<currentNumberOfBooks -1 ; i++)
        {
            if(allBooks[i].numberOfTimesBorrowed<allBooks[i+1].numberOfTimesBorrowed)
            {
                temp =allBooks[i];
                allBooks[i] = allBooks[i+1];
                allBooks[i+1]=temp;
                flag++;
            }
        }
        if(!flag)break;
    }
}


int util_check_only_numbers(char* stringToValidate)
{
    int i ,l = strlen(stringToValidate);
    for(i = 0 ; i< l ; i++)
    {
        if(!isdigit(stringToValidate[i]))return 0;
    }
    return 1;
}

int to_int(char* st , int n)
{
    if(!*st)return 0;
    return n==1?(int)(*st-'0'):(int)(*st-'0')*myPower(10,n-1) + to_int(st+1,n-1);
}

int myPower(int n ,int z)
{
    return z==0?1:n*myPower(n,z-1);
}

char*  util_get_date_format_from_date_object(Date* date)
{
    char*  d = malloc(12);
    // printf("\n%d %d %d \n",date.day,date.month,date.year);
    sprintf(d,"%0d/%0d/%0d",date->day,date->month,date->year);
    return d;

}


int util_valid_email_address(char* EmailAddress){
	if(!EmailAddress) // If cannot read the Email Address...
		return 0;
	if(!isalpha(EmailAddress[0])) // If the First character is not A-Z, a-z
		return 0;
	int AtOffset = -1;
	int DotOffset = -1;
	int cntat=0;
	unsigned int Length = strlen(EmailAddress); // Length = StringLength (strlen) of EmailAddress
	for(unsigned int i = 0; i < Length; i++)
	{
	    if(EmailAddress[i] == '@'){ // If one of the characters is @, store it's position in AtOffset and counting no of @
			AtOffset = (int)i;
			cntat++;
		}
		else if(EmailAddress[i] == '.'){// Same, but with the dot
            if(EmailAddress[i-1]=='-'||EmailAddress[i+1]=='-')return 0;//check for -.and.-
			DotOffset = (int)i;
		}
	}
	if(cntat!=1)return 0;
	if(AtOffset == -1 || DotOffset == -1) // If cannot find a Dot or a @
		return 0;
	if(AtOffset > DotOffset) // If the @ is after the Dot
		return 0;
    for(int i=DotOffset;i<(int)Length;++i)//. no digit
        if(isdigit(EmailAddress[i]))return 0;
    return (DotOffset+3>=(int)Length-1);//check .com .net .co
	return !(DotOffset >= ((int)Length-1)); //Check there is some other letters after the Dot
}

void util_to_lower_string(char* input){
for(unsigned int i =0 ; input[i]!='\0' ;i++){
input[i]= tolower(input[i]);
}
}

int util_comp_dates(Date a , Date b){
if(a.year < b.year)return -1;
if(a.year > b.year)return 1;
if(a.month < b.month)return -1;
if(a.month > b.month)return 1;
if(a.day < b.day)return -1;
if(a.day > b.day)return 1;
return 0;
}
int util_member_has_borrowed_book(int idToCheck){
for(int i =0 ;i <currentNumberOfBorrowedBooks ;i++){
if(allBorrowedBooks[i].userID == idToCheck)return 1;
}
return 0;
}
void util_trim_white_space(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;
}
