#include "push_swap.h"

t_list	*addlst(int num, t_list *st)
{
	t_list *ptr = st; //これを使ってallfreeする。
	if (st == NULL)
	{
		st = malloc(sizeof(t_list));
		if (st == NULL)
			return (NULL);
		st->value = num;
		st->next = NULL;
		st->prev = NULL;
		return (st);
	}
	else
	{
		st->next = malloc(sizeof(t_list));
		if (st == NULL)
			return (NULL); //ここでptrを使って全部freeしていく予定
		st->next->value = num;
		st->next->next = NULL;
		st->next->prev = ptr;
		return (st->next);
	}
}

t_list	*push_stack_a_to_b(t_list *lsta, t_list *lstb)
{
	t_list *ptr;

	if (lsta == NULL)
		return (NULL);
	if (lstb == NULL)
	{
		lsta->next->prev = NULL;
		// ptr = lsta->next; //次の先頭のやつを保存
		lsta->next = NULL;
		lsta->prev = NULL;
		return (lsta); //次の先頭を返す
	}
	else
	{
		lsta->next->prev = NULL;
		lsta->next = lstb;
		lstb->prev = lsta;
		lsta->prev = NULL;
		return (lsta);
	}
}