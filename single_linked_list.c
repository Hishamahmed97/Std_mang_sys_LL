 #include "single_linked_list.h"

//create list 
sll_t * create_sll()
{
    sll_t * newList = malloc(1 * sizeof(sll_t));
    if(newList == NULL)
    {
        return NULL; 
    }
    newList->head = NULL; 
    newList->size = 0 ; 

    return newList; 
}
     

//create node 
node_t * create_node()
{
    node_t * newNode = malloc(1*sizeof(node_t));

    if(newNode ==NULL)
    {
        return NULL; 
    } 
    
    fflush(stdin);
    printf("enter Employee name \n");
    //scanf("%[^\n]s",newNode->name); 
    fgets(newNode->name,Max_Name_Size,stdin);
    
    fflush(stdin);
    printf("enter Employee title \n");
    //scanf("%[^\n]s",newNode->title);
    fgets(newNode->title,Max_Title_Size,stdin);
    
    fflush(stdin);  
    printf("enter Employee ID \n");
    scanf("%d",&newNode->ID);
    
    fflush(stdin);
    printf("enter Employee Age \n");
    scanf("%d",&newNode->age);

    fflush(stdin);
    printf("enter Employee Salary \n");
    scanf("%d",&newNode->salary);

    newNode->next = NULL;

    return newNode; 

}

//free list 
void free_sll(sll_t * list)
{
    if(list == NULL)
    {
        return; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return; 
    }

    node_t * current = list->head; 

    while (current !=NULL)
    {
        list->head = list->head->next; 
        free(current); 
        current = list->head; 
        list->size--; 
    }

    free(list); 
}

//function to append node 
EN_sll_status_t append_node(sll_t * list)
{
    if(list == NULL)
    {
        return SLL_NULL_POINTER; 
    }

    node_t * newNode = create_node(); 

    if(newNode == NULL)
    {
        return SLL_NODE_NOT_CREATED; 
    }

    node_t * current = list->head; 
    //check if the list is empty 

    if(list->head == NULL)
    {
        list->head = newNode; 
    }
    else
    {
        while (current->next !=NULL)
        {
            current = current->next; 
        }
        //now current points at the last node in the list 
        current->next = newNode; 
    }

    list->size++; 
    
    return SLL_OK; 

}



//funciton to display list 
EN_sll_status_t dipslay_sll(sll_t * list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return SLL_EMPTY_LIST; 
    }

    node_t * current = list->head; 

    while (current !=NULL)
    {
        printf("Employee name   : %s \n", current->name);  
        printf("Employee title  : %s \n",current->title);
        printf("Employee ID     : %d \n",current->ID);
        printf("Employee Salary : %d \n",current->salary);
        printf("Employee Age    : %d \n",current->age);
        printf("\n --------------------------------- \n");
        current = current->next; 
    }
    printf("\n"); 
    return SLL_OK; 
}



//function to modify name by ID
EN_sll_status_t modify_list_sll_name(sll_t * list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return SLL_EMPTY_LIST; 
    }
    
    int ID = 0;
    printf("Enter EMP ID \n");
    scanf("%d",&ID);

    char name[Max_Name_Size];

    fflush(stdin);
    printf("Enter New EMP Name \n");
    fgets(name,Max_Title_Size,stdin);

    node_t * current = search_node_sll_ID(list , ID); 

    if(current == NULL)
    {
        return SLL_NODE_NOT_FOUND; 
    }

    for (int i = 0;i<Max_Name_Size;i++)
    {
        current->name[i] = name[i]; 
    }
    printf("new name is %s \n",current->name);
    return SLL_OK; 
}

//function to modify title by ID
EN_sll_status_t modify_list_sll_title(sll_t * list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return SLL_EMPTY_LIST; 
    }
    
    int ID = 0;
    printf("Enter EMP ID \n");
    scanf("%d",&ID);

    char title[Max_Name_Size];

    fflush(stdin);
    printf("Enter New EMP title \n");
    fgets(title,Max_Title_Size,stdin);

    node_t * current = search_node_sll_ID(list , ID); 

    if(current == NULL)
    {
        return SLL_NODE_NOT_FOUND; 
    }

    for (int i = 0;i<Max_Name_Size;i++)
    {
        current->title[i] = title[i]; 
    }
    printf("new title is %s \n",current->title);
    return SLL_OK; 
}

// function to search by ID
node_t * search_node_sll_ID(sll_t * list , int ID)
{
    if(list ==NULL)
    {
        return NULL; 
    }
    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return NULL; 
    }

    node_t * current = list->head; 

    while (current != NULL)
    {
         
        if(current->ID == ID)
        {
           
            return current; 
        }
        current = current->next; 
    }

    printf("value not found\n"); 
    return NULL; 
    

}

//funciton to display certain emp by ID 
EN_sll_status_t dipslay_sll_emp(sll_t * list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return SLL_EMPTY_LIST; 
    }
    printf("Enter Employee ID \n");
    int ID;
    scanf("%d",&ID);

    node_t * current = search_node_sll_ID(list,ID); 

    if (current != NULL)
    {
        printf("Employee name   : %s \n", current->name);  
        printf("Employee title  : %s \n",current->title);
        printf("Employee ID     : %d \n",current->ID);
        printf("Employee Salary : %d \n",current->salary);
        printf("Employee Age    : %d \n",current->age);
        printf("\n --------------------------------- \n");
    }
        
    else 
    {
    printf("ID not exist \n");
    }

    return SLL_OK; 
}

//function to delete node by ID 
EN_sll_status_t _sll_delete_byValue(sll_t * list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER; 
    }

    if(list->head == NULL)
    {
        printf("empty list \n"); 
        return SLL_EMPTY_LIST; 
    }

    node_t * current = list->head , *prev; 
    int ID;
    printf("Enter Emp ID \n");
    scanf("%d",&ID);

    if(list->head->ID == ID)
    {
        list->head = list->head->next; 
        free(current); 
        list->size--; 
        return SLL_OK; 
    }

    while (current!=NULL)   
    {
        if(current->ID == ID)
        {
            break;
        }
        prev =current; 
        current = current->next; 
    }
    
    if(current == NULL)
    {
        printf("value not found\n"); 
        return SLL_NODE_NOT_FOUND; 
    }

    prev->next = current->next; 
    printf("Employee num %d deleted \n",current->ID);
    free(current); 
    list->size--; 

    return SLL_OK; 



}

