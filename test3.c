#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>



typedef struct s_list{

    int value;
    struct s_list *next;

}   t_list;

t_list *swapfirst(t_list *lst);
t_list *rotationfirstlast(t_list *lst);
t_list *push_stack_ab(t_list *lsta,t_list *lstb);
t_list *addlst(int num, t_list *st);
int *rank(int *lst,int arg_num, int max, int num);
void printstack(t_list *lst);

t_list *addlst(int num, t_list *st)
{
    t_list *ptr = st;//これを使ってallfreeする。

    if(st == NULL)
    {
        st = malloc(sizeof(t_list));
        if(st == NULL)
            return NULL;
        st->value = num;
        st->next = NULL;
        return ptr;
    }
    else
    {
        st->next = malloc(sizeof(t_list));
        if(st == NULL)
        {
            return NULL;//ここでptrを使って全部freeしていく予定
        }
        st = st->next;
        st->value = num;
        st->next = NULL;
        return ptr;
    }
}


void printstack(t_list *lst)
{
    while(lst != NULL)
    {
        printf("%d\n",lst->value);
        lst = lst->next;
    }
}

t_list *push_stack_ab(t_list *lsta,t_list *lstb)
{
    t_list *nextptr;

    if(lsta == NULL)
        return NULL;
    if(lstb == NULL)
    {
        nextptr = lsta->next;
        lsta->next = NULL;
        return nextptr;
    }
    else
    {
        nextptr = lsta->next;
        lsta->next = lstb;
        return nextptr;
    }
        
}

t_list *rotationfirstlast(t_list *lst)
{
    t_list *bef_first;
    t_list *aft_first;

    bef_first = lst;//最後の次の場所を渡すために保存
    aft_first = lst->next;//次の最初の場所をreturnで返すために保存
    while(lst->next != NULL)
    {
        lst = lst->next;
    }//終点まで繰り返す
    lst->next = bef_first;//最後のところに次の場所Aを指定して追加
    lst = lst->next;//Aに移動します
    lst->next = NULL;//最後の次はないよねーー
    return aft_first;
}

t_list *swapfirst(t_list *lst)
{
    t_list *bef_first;
    t_list *third;
    t_list *aft_first;

    bef_first = lst;//リストの元一番上Aのテータ場所を保存
    aft_first = lst->next;//先頭にしたいBの場所を保存
    lst = lst->next;//リストの元２番目Bのデータ場所に移動
    third = lst->next;//次のデータである３番目Cのポインタを保存（今は２番目の場所にいる）
    lst->next = bef_first;//Bの次をAに指定し、Bが先頭になる。（まだ２番目）
    lst = lst->next;//Aに移動する。
    lst->next = third;//Aの次をCに指定し、swap完了になる。
    return aft_first;

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



//とりあえずスタックに入れるのはできた。途中でmallocに失敗したらそれまでを全部解放するために双方向にしとく
//次に必要なのは、
//一連の流れは、スタックにぶちこむ、操作をする。その結果ソートされている。
//だから次は操作が必要。操作を作ろう。常にリストの始めの部分にポインタがあるように設定する。
//操作は多分ほぼできてる。問題はどうやってソートしていくか
//問題は最終的な概形というか順番を事前に知っているかどうか、毎回同時に判断してソート移動させるのは流石に荷が重すぎるから判断は別でいいと思う、毎回やってたら計算量も時間かかりすぎるし
//構造体にフラグというか順番みたいなのを導入して、最初に二重配列にして動かす。←やっぱ嘘普通にrankでvalueにぶち込めばいい
//与えた数字列の大きさを判定するrank関数を作りたい。作った。これをvalueに入れる。
//

int main(int argc, char *argv[])
{
    t_list *x = NULL;
    t_list *y;
    int *return_sort;
    int sort[argc];
    int i = 1;

    while(i < argc)
    {
        sort[i - 1] = atoi(argv[i]);
        i++;
    }

    return_sort = rank(sort,argc,0,0);
    i = 0;
    while(i < argc)
    {
        x = addlst(return_sort[i],x);
        // printf("%d\n",x->value);
        x = x->next;
        if(i == 0)
            y = x;
        i++;
    }
    printstack(y);

}


// int *rank(int *lst,int arg_num, int max, int num)
// {
//     int *sorted;
//     int i;
//     static int j;

//     sorted = (int *)malloc(arg_num * sizeof(int));
//     if (sorted == NULL)
//         return NULL;
//     while(j < arg_num)
//     {
//         i = 0;
//         max = 0;
//         while(i < arg_num)
//         {
//             if(max < lst[i])
//             {
//                 max = lst[i];
//                 num = i;
//             }
//             i++;
//         }
//         lst[num] = -1;
//         sorted[num] = arg_num - j;
//         j++;
//     }
//     return sorted;
// }

// int main(int argc, char *argv[])
// {
//     t_list *x = NULL;
//     t_list *y = NULL;
//     int *return_sort;
//     int sort[argc];
//     int i = 1;

//     while(i < argc)
//     {
//         sort[i - 1] = atoi(argv[i]);
//         i++;
//     }
//     return_sort = rank(sort,argc,0,0);
//     while(i < argc)
//     {
//         x = addlst(return_sort[i],x);
//         i++;    
//     }

// }






// int main(int argc, char *argv[])
// {
//     int lst[argc - 1];
//     int *printing;
//     int i;

//     i = 1;
//     while(i < argc)
//     {
//         lst[i - 1] = atoi(argv[i]);
//         i++;
//     }

//     printf("argc :%d\n",argc);
//     printing = rank(lst,argc - 1,0,0);

//     i = 0;
//     while(i < argc -1)//ここ+10とかしてみるとセグフォの元かも、
//     {
//         printf("%d %d\n",lst[i],printing[i]);
//         i++;
//     }
//         free(printing);
//     return 0;
// }


// char *rank(int *lst,int arg_num)
// {
//     char *sorted;
//     int i;
//     int max;
//     int num;
//     static int j;

//     while(j < arg_num)
//     {
//         i = 0;
//         max = 0;
//         while(i < arg_num)
//         {
//             if(max < lst[i])
//             {
//                 max = lst[i];
//                 num = i;
//             }
//             i++;
//         }
//         lst[num] = -1;
//         sorted[num] = arg_num - j + '0';
//         j++;
//     }
//     sorted[arg_num] = '\0';
//     return sorted;
// }