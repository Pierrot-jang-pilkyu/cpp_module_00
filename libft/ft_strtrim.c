#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*buf;
	char	*result;

	len = (start = (end = 0));
	while (s1[len])
		len++;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = len - 1;
	while (s1[end] && is_set(s1[end], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	buf = result;
	while (start <= end)
		*buf++ = s1[start++];
	*buf = '\0';
	return (result);
}
