#include "push_swap.h"

int	*rank(int *lst, int arg_num, int max, int num)
{
	int			*sorted;
	int			i;
	static int	j;

	sorted = (int *)malloc(arg_num * sizeof(int));
	if (sorted == NULL)
		return (NULL);
	while (j < arg_num)
	{
		i = 0;
		max = 0;
		while (i < arg_num)
		{
			if (max < lst[i])
			{
				max = lst[i];
				num = i;
			}
			i++;
		}
		lst[num] = -1;
		sorted[num] = arg_num - j;
		j++;
	}
	return (sorted);
}

t_list *back_to_Firstptr(t_list *lst)
{
    while(lst->prev != NULL)
    {
        lst = lst->prev;
    }
    return lst;
}

void	printstack(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->value);
		if(lst -> next != NULL)
			lst = lst->next;
		else
			break;
	}
}