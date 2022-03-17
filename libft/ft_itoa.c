#include "libft.h"

static long long int	ft_pow(int n, int power)
{
	long long int	result;

	if (power >= 0)
	{
		result = 1;
		while (power-- > 0)
			result *= n;
	}
	else
		return (0);
	return (result);
}

static int	digits_of(long long int n)
{
	int	result;
	int	power;

	result = (power = 0);
	while (n / ft_pow(10, power++))
		result++;
	return (result);
}

char	*ft_itoa(int n)
{
	char			*buf;
	char			*result;
	int				len;
	long long int	tmp;

	tmp = n;
	len = digits_of(tmp);
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	buf = result;
	if (tmp < 0)
	{
		tmp = -tmp;
		*buf = '-';
		buf++;
	}
	while (--len >= 0)
	{
		*buf++ = (tmp / ft_pow(10, len) + '0');
		tmp = tmp % ft_pow(10, len);
	}
	*buf = '\0';
	return (result);
}
