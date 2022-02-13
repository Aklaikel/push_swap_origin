#include <stdio.h>
#include "push_swap.h"

void    disp(t_list *a, char *str)
{
    if (str)
        printf("%s", str);
    while (a)
    {
        printf("%d  ", a->content);
        a = a->next;
    }
    printf("\n");
}