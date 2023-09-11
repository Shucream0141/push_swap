#include "push_swap.h"

t_list	*rotationfirstlast(t_list *lst)
{
	t_list	*first_to_last;
	t_list	*second_to_first;

	if (lst == NULL)
		return (NULL);
	first_to_last = lst;
	second_to_first = lst->next;
	second_to_first->prev = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = first_to_last;
	first_to_last->next = NULL;
	first_to_last->prev = lst;
	printf("now...rotate\n");
	return (second_to_first);
}

t_list	*swapfirst(t_list *lst)
{
	t_list	*bef_first;
	t_list	*third;
	t_list	*aft_first;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	bef_first = lst;
	aft_first = lst->next;
	third = lst->next->next;

	bef_first->next = third;
	bef_first->prev = aft_first;
	aft_first->prev = NULL;
	aft_first->next = bef_first;
	third->prev = bef_first;
	printf("now...swap\n");
	return (aft_first);
}

t_list	*rotate_a_and_b(t_list *lsta, t_list *lstb)
{
	lsta = rotationfirstlast(lsta);
	lstb = rotationfirstlast(lstb);
	return (lsta);
}

t_list	*swap_a_and_b(t_list *lsta, t_list *lstb)
{
	lsta = swapfirst(lsta);
	lstb = swapfirst(lstb);
	return (lsta);
}

t_list	*reverse_rotate(t_list *lsta)
{
	t_list	*first_to_second;
	t_list	*last_to_first;

	if (lsta == NULL || lsta->next == NULL)
		return (NULL);
	first_to_second = lsta;
	while (lsta->next != NULL)
	{
		lsta = lsta->next;
	}
	last_to_first = lsta;
	last_to_first->prev->next = NULL;
	first_to_second->prev = last_to_first;
	last_to_first->next = first_to_second;
	last_to_first->prev = NULL;
	printf("now...rra\n");
	return (last_to_first);
}

t_list	*rra(t_list *lsta, t_list *lstb)
{
	lsta = reverse_rotate(lsta);
	lstb = reverse_rotate(lstb);
	return (lsta);
}
//変更する部分は、１番目の場所を保持して、prevに最後のやつをわり当てる。
//次に先頭のnextに１番目のポインタを指定する。
//返すのは新しい先頭の位置だから、ptr->next != NULLな最初０最後１のポインタを保持
//最初９最後０のポインタのnextをNULLにする。
