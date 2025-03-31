#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((s1[i] == '+' && s2[j] == '+') || (s1[i] == '-' && s2[j] == '-'))
	{
		i++;
		j++;
	}
	else if (s1[i] == '+' && (s2[j] >= '1' && s2[j] <= '9'))
		i++;
	else if (s2[j] == '+' && (s1[i] >= '1' && s1[i] <= '9'))
		j++;
	if (s2[i] == '0')
		while (s2[j] != '0')
			j++;
	else if (s1[i] == '0')
		while (s1[i] == '0')
			i++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i++] == s2[j])
		j++;
	return (s1[i] - s2[j]);
}
