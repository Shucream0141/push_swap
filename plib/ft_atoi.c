#include "../push_swap.h"
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