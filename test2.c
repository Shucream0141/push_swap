//ここは双方向リストにしている。
//これは
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{

    char *str;
    struct s_list *next;
    struct s_list *prev;

}   t_list;

t_list *addlst(char *kotoba, t_list *st)
{
    void *ptr;

    if(st == NULL)
    {
        st = malloc(sizeof(t_list));
        st->str = kotoba;
        st->next = NULL;
        st->prev = NULL;
        return st;
    }
    else
    {
        st->next = malloc(sizeof(t_list));
        ptr = st;
        st = st->next;
        st->str = kotoba;
        st->next = NULL;
        st->prev = ptr;
        return st;
    }
}

t_list *back_to_Firstptr(t_list *lst)
{
    while(lst->prev != NULL)
    {
        lst = lst->prev;
    }
    return lst;
}

void printstack(t_list *lst)
{
    int i = 0;
    while(lst != NULL)
    {
        printf("[%d]番目 %s\n",i,lst->str);
        lst = lst->next;
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_list *x = NULL;
    int i = 1;

    while(i < argc)
    {
        x = addlst(argv[i],x);
        i++;    
    }
    x = back_to_Firstptr(x);
    printstack(x);

}



//とりあえずスタックに入れるのはできた。途中でmallocに失敗したらそれまでを全部解放するために双方向にしとく
//次に必要なのは、
//一連の流れは、スタックにぶちこむ、操作をする。その結果ソートされている。
//だから次は操作が必要。操作を作ろう。

// t_list *push_stackab(t_list *lsta,t_list *lstb)
// {
//     if(lsta == NULL)
//         return NULL;
//     if(lstb == NULL)
//     {
//         lstb = malloc(sizeof(t_list));
//         st->str = kotoba;
//         st->next = NULL;
//         st->prev = NULL;        
//     }
// }