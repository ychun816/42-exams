#include "ft_list.h"

//METHOD A//
int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

//METHOD B//
int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	
	if (!begin_list)
		return (0);
	if (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}