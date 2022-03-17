#include "libft.h"

int	ft_isalnum(int c)
{
	if ('A' <= c && !('Z' < c && c < 'a') && c <= 'z')
		return (c);
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}
