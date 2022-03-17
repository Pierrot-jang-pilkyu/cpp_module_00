#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = (dst_len = (src_len = 0));
	while (src[src_len])
		src_len++;
	while (dst[dst_len])
		dst_len++;
	while (src[i] && i + dst_len + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	else
		return (dst_len + src_len);
}
