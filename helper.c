#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tag_node
{
    
    char name[3];
}node_t;




void main()
{
char tt[3]  = {'a','h','a'};

    node_t * current = malloc(1*sizeof(node_t));

    for (int i = 0;i<3;i++)
    {
    current->name[i] = tt[i];
    }

    printf("%s",current->name);


    free(current);



    
}





    
