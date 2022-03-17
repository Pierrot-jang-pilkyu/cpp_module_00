#include "libft.h"

int	ft_isalpha(int c)
{
	if ('A' <= c && !('Z' < c && c < 'a') && c <= 'z')
		return (c);
	return (0);
}
