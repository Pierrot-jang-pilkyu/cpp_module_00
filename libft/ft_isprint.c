#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c < 127)
		return (c);
	return (0);
}
