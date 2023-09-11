#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list{

    int value;
    struct s_list *next;

}   t_list;

static int	over(long *num, const char *str, int count)
{
	if (count == 0 && ((*num > LONG_MAX / 10) || (*num == LONG_MAX / 10 && *str
				- '0' > LONG_MAX % 10)))
	{
		*num = LONG_MAX;
		return (1);
	}
	else if (count == 1 && ((*num > LONG_MIN / 10 * -1) || (*num == LONG_MIN
				/ 10 * -1 && *str - '0' > LONG_MIN % 10 * -1)))
	{
		*num = LONG_MIN;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		count;
	long	num;

	num = 0;
	count = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (over(&num, str, count))
			return (num);
		num = num * 10 + *str - '0';
		str++;
	}
	if (count == 1)
		num *= -1;
	else if (count > 1)
		num = 0;
	return (num);
}

void printstack(t_list *lst)
{
    printf("今ここ\n");
    while(lst != NULL)
    {
        printf("来てないぞ\n");
        printf("%d\n",lst->value);
        lst = lst->next;
        printf("ここまではきた\n");
    }
}

t_list *addlst(int num, t_list *st)
{
    // t_list *ptr = st;//これを使ってallfreeする。

    if(st == NULL)
    {
        st = malloc(sizeof(t_list));
        if(st == NULL)
            return NULL;
        st->value = num;
        st->next = NULL;
        return st;
    }
    else
    {
        st->next = malloc(sizeof(t_list));
        if(st->next == NULL)
        {
            return NULL;//ここでptrを使って全部freeしていく予定
        }
        st = st->next;
        st->value = num;
        st->next = NULL;
        return st;
    }
}

int *rank(int *lst,int arg_num, int max, int num)
{
    int *sorted;
    int i;
    static int j;

    sorted = (int *)malloc(arg_num * sizeof(int));
    if (sorted == NULL)
        return NULL;
    while(j < arg_num)
    {
        i = 0;
        max = 0;
        while(i < arg_num)
        {
            if(max < lst[i])
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
    return sorted;
}


int main(int argc, char *argv[])
{
    t_list *x = NULL;
    t_list *y = NULL;
    t_list *z = NULL;

    int *return_sort;
    int sort[argc];
    int i = 1;

    while(i < argc)
    {
        sort[i - 1] = atoi(argv[i]);
        i++;
    }
    i = 0;
    while(i < argc - 1)
    {
        printf("%d\n",sort[i]);
        i++;
    }

    return_sort = rank(sort,argc -1 ,0,0);
    i = 0;
    while(i < argc - 1)
    {
        printf("%d\n",return_sort[i]);
        i++;
    }
    i = 0;
    while(i < argc -1)
    {
        x = addlst(return_sort[i],x);
        printf("来ました%d\n",x->value);
        if(i == 0)
            y = x;
        i++;
    }
    printstack(y);

}

// int main(int argc, char *argv[])
// {
//     t_list *x = NULL;
//     int i;

//     i = 1;
//     while(i < argc)
//     {
//         x = addlst(atoi(argv[i]),x);
//         printf("%d\n",x->value);
//         x = x->next;
//         i++;
//     }
// }