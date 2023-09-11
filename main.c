#include "push_swap.h"

//とりあえずスタックに入れるのはできた。途中でmallocに失敗したらそれまでを全部解放するために双方向にしとく、うーん複雑だし単方向で
//次に必要なのは、
//一連の流れは、スタックにぶちこむ、操作をする。その結果ソートされている。
//だから次は操作が必要。操作を作ろう。常にリストの始めの部分にポインタがあるように設定する。
//操作は多分ほぼできてる。問題はどうやってソートしていくか
//問題は最終的な概形というか順番を事前に知っているかどうか、毎回同時に判断してソート移動させるのは流石に荷が重すぎるから判断は別でいいと思う、毎回やってたら計算量も時間かかりすぎるし
//構造体にフラグというか順番みたいなのを導入して、最初に二重配列にして動かす。
//

//与えた数字列の大きさを判定するrank関数を作りたい。作った。これをvalueに入れる。
//valueで順番はわかった。次に必要なのは仕分け方、分割するほどソートの手間がなくなるのだから、まずは大きさの順番の中央値より大きいか小さいかで分ける。
//

int	main(int argc, char *argv[])
{
	t_list	*x;
	t_list	*y;
	int		*return_sort;
	int		*sort;
	int		i;

	sort = (int *)malloc(argc * sizeof(int));
	x = NULL;
	y = NULL;
	i = 1;
	while (i < argc)
	{
		sort[i - 1] = atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("before sorting ;%d\n", sort[i]);
		i++;
	}
	return_sort = rank(sort, argc - 1, 0, 0);
	i = 0;
	while (i < argc - 1)
	{
		printf("sort %d return_sort %d ",sort[i], return_sort[i]);
		x = addlst(return_sort[i], x);
		printf("value %d\n", x->value);
		i++;
	}
	x = back_to_Firstptr(x);
	if (argc == 4)
	{
		x = ft_sort_three(x);
	}
	x = back_to_Firstptr(x);
	printstack(x);
	// if (argc == 6)
	// {
	// 		x = ft_sort_five(x);
	// }
	// printf("swap\n");
	// x = swapfirst(x);
	// printstack(x);
	// printf("rotate\n");
	// x = rotationfirstlast(x);
	// printstack(x);
	// printf("reverse rotate\n");
	// x = reverse_rotate(x);
	// printstack(x);
}
