#include "single_linked_list.h"
#include <conio.h>
#include <stdlib.h>

void main()
{
    // ***** EMP Managment Record ****** //
    // to add new employee data
    // to delete data of certain employee by ID
    // to modify certain employee data by ID
    // to view data of an employee
    // *** EMP Name, Age, Salary, Title, ID **** //

    sll_t * my_list =  create_sll();   

    // pre-defined some nodes
    
    // below code for based on user choice
    int choice = 1;
    char cont = 'Y';
    system("cls");

    while (cont == 'Y' || choice != 0)
    {
        printf("\n *** main menu ***\n");
        printf("press 1 for adding emp\n");
        printf("press 2 for displaying all emp\n");
        printf("press 3 for display certain emp by ID \n");
        printf("press 4 for modifing Name \n");
        printf("press 5 for modifing Title \n");
        printf("press 6 for deleting Emp \n");
        printf("press 0 exit\n");
        printf("Enter your choice :\n");
        scanf("%d",&choice);
        system("cls");

        switch(choice)
        {
            case 1:
            {
            append_node(my_list);
            break;
            }

            case 2:
            {
            dipslay_sll(my_list);
            break;
            }

            case 3:
            {
            dipslay_sll_emp(my_list);
            break;
            }

            case 4:
            {
            modify_list_sll_name(my_list);
            break;
            }

            case 5:
            {
            modify_list_sll_title(my_list);
            break;
            }

            case 6:
            {
            _sll_delete_byValue(my_list);
            break;
            }
            
            case 0:
            {
            free_sll(my_list);
            exit(1);
            }

            default:
            printf("invalid choice ... please enter a valid choice \n");

        }
        printf("Press Y to continue \n");
        scanf("%s",&cont);
        system("cls");
    }

    free_sll(my_list);
    system("cls");
 
}