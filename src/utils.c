#include "pushswap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t	i;
	char	*ptrdest;
	char	*ptrsrc;

	if (dest == NULL && src == NULL)
		return (0);
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	i = 0;
	while (i < num)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (ptrdest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;

	if (dest == NULL || src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dest, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}

long long int	ft_atoll(const char *str)
{
	long long int	nb;
	long long int	sign;
	int				i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		nb *= 10;
		nb += ((int)str[i] - '0');
		i++;
	}
	return (nb * sign);
}
