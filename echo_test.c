#include <stdio.h>

int	ft_check_nl(char *str)
{
	if (!str)
		return (0);
	if(*str == '-')
	{
		str++;
		while (str && *str)
		{
			if (*str == 'n')
				str++;
			else
				return (0);
		}
	}
	return (1);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	nl;

	i = 1;
	nl = 0;
	if (!cmd)
		return ;
	if (ft_check_nl(cmd[i]))
	{
		nl = 1;
		printf("%d\n",ft_check_nl(cmd[i]) );
		while (*cmd && ft_check_nl(cmd[i]))
			i++;
	}
	// if (nl)
	// 	printf("%s\n", cmd[i - 1]);
	// else
	// 	printf("%s", cmd[i - 1]);
	printf("%d\n", nl);
}

int main(int argc, char **argv)
{
	ft_echo(argv);
}