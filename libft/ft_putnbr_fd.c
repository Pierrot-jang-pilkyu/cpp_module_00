#include "libft.h"

static void	put_recursive(long long int n, int fd)
{
	char	c;

	if (n > 9)
		put_recursive(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = -tmp;
	}
	put_recursive(tmp, fd);
}
