 #ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Name_Size 10
#define Max_Title_Size 10

typedef char data_t;


typedef struct tag_node
{
    
    struct tag_node * next; 
    int age;
    int ID;
    int salary;
    char title[Max_Title_Size];
    char name[Max_Name_Size];
    
}node_t;

typedef struct 
{
    node_t * head; 
    unsigned int size; 
}sll_t;

typedef enum{
    SLL_NODE_NOT_CREATED,
    SLL_NODE_NOT_FOUND,
    SLL_OK,
    SLL_NULL_POINTER,
    SLL_EMPTY_LIST,
    SLL_INVALID_POSITION,
    SLL_NOT_OK,
    SLL_APPEND_FLAG
}EN_sll_status_t; 


//create list 
sll_t * create_sll(); 

//create node 
node_t * create_node(); 

//free list 
void free_sll(sll_t * list); 

//function to append node 
EN_sll_status_t append_node(sll_t * list); 

//funciton to display list 
EN_sll_status_t dipslay_sll(sll_t * list); 

// function to modify name of node by ID
EN_sll_status_t modify_list_sll_name(sll_t * list);

// function to modify title of node by ID
EN_sll_status_t modify_list_sll_title(sll_t * list);

//function to search for ID
node_t * search_node_sll_ID(sll_t * list , int ID);

//funciton to display certain employee
EN_sll_status_t dipslay_sll_emp(sll_t * list);

//function to delete employee by ID
EN_sll_status_t _sll_delete_byValue(sll_t * list);



#endif