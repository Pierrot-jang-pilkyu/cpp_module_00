#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = (j = (n_len = 0));
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[n_len])
		n_len++;
	while (haystack[i] && i + n_len < len)
	{
		if (haystack[i] == needle[0])
		{
			j = -1;
			while (needle[++j])
				if (haystack[i + j] != needle[j])
					return (NULL);
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
