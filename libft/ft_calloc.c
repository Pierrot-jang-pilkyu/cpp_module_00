#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	void			*result;
	unsigned char	*temp;

	i = count * size;
	result = malloc(i);
	if (!result)
		return (NULL);
	temp = result;
	while (i--)
	{
		temp[i] = 0;
	}
	return (result);
}
