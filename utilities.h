#include "control.h"
#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
int util_validate_only_alphabets(char*);
int util_validate_no_special_characters(char*);
int util_validate_ISBN_format(char*);
Date* util_get_current_OS_date();
Date* util_get_date_from_string(char*);
int util_check_for_ISBN_exist(char*);
int util_check_for_ID_exist(int);
int util_check_for_borrowed_book(int,char*);
int util_check_only_numbers(char*);
int util_generate_ID();
void util_sort_members_by_id();
void util_sort_books_number_of_times_borrowed();
int to_int(char* st , int n);
int myPower(int n ,int z);
Date util_add_14days_to_date(Date);
char*  util_get_date_format_from_date_object(Date*);
int util_comp_dates(Date,Date);
int util_valid_email_address(char*);
void util_to_lower_string(char*);
int util_member_has_borrowed_book(int);
void util_trim_white_space(char*);
#endif // UTILITIES_H_INCLUDED
