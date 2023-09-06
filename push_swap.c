#include "push_swap.h"


void  stackprint(t_list *stack)
{
    printf("%d\n",stack->content);
}


t_list *stackman(t_list *prev,int num)
{
    prev->next = ft_lstnew(num);
    return prev->next;
}

int main(int argc, char *argv[])
{
    int i = 1;
    int num;
    t_list *new;

    while(i < argc)
    {
        new = ft_lstnew(ft_atoi(argv[i]));

        new->next = new;
        i++;
    }
    return 0;
}

//ここから拡張していく。まず必要なのは大小の数値比較だからatoiにぶち込んで(ok)スタックに積みたい。
//構造体にちゃんと数字が積めているか格納できてるか確かめる関数を作る。
//