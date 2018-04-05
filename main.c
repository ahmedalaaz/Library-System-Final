#include <stdio.h>
#include "view.h"
#include "control.h"
int main()
{
    control_initialize_all_books();
    control_initialize_all_members();
    control_initialize_all_borrowed_books();
    view_main_menu();
    return 0;
}
