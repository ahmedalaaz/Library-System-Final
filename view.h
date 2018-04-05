#include "control.h"
#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_BOLD_BLUE "\x1b[1;34m"
#define COLOR_DARK_GREEN "\x1b[1;30m"

void view_main_menu();

void view_book_management();

void view_member_management();

void view_borrow_management();

void view_admin_actions();

void view_exit_page();

void view_get_book_search_query();

void view_search_for_a_book_title();

void view_search_for_a_book_author();

void view_search_for_a_book_ISPN();

void view_search_for_a_book_category();

void view_multi_search();

Book* view_get_book_info();

int  view_get_book_ISPN(int);

Member* view_get_member_info();

int view_get_member_ID();

int view_get_borrowed_book_index();

void view_print_date_formated(Date);

void view_print_all_book();

void view_print_all_members();

void view_print_all_borrowed_books();


void view_print_overdue_books();

void view_print_most_popular_books();

void view_add_new_copy();

BorrowedBook* view_get_borrowed_book_info();

void view_fatal_error();

void console_sleep(int);

void clear_console();

#endif // VIEW_H_INCLUDED
