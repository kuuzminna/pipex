#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    struct  list *temp,  *p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr;
    lst->ptr = temp;
    lst->ptr = NULL;
    return(temp);
}