// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;

	//check bign list NULL
	if (!*begin_list || !begin_list)
		return (NULL);
	current = *begin_list;
	//cmp => find dat_ref in begin_list => free+ remove
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else //free +remove
	{
		current = *begin_list;// Set current to the current head of the list
		ft_list_remove_if(begin_list, data_ref, cmp);// Recursively call on the next node
	}
}