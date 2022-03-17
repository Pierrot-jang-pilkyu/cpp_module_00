#include "libft.h"

static int	get_total_len(const char *s1, const char *s2)
{
	int	len1;
	int	len2;

	len1 = (len2 = 0);
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	return (len1 + len2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	char	*buf;
	char	*join;

	total_len = get_total_len(s1, s2);
	join = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!join)
		return (NULL);
	buf = join;
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (join);
}
