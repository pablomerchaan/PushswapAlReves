#include "pushswap.h"

struct s_intsaux	completeints(struct s_intsaux ints, struct s_l list, struct s_rots goodrot)
{
	ints.steps += goodrot.cost + 1;
	ints.i = list.partition;
	while (ints.i < list.length)
	{
		if (list.list[ints.i] <= ints.current_max)
			break ;
		ints.i++;
	}
	return (ints);
}

char	**solveargv(int argc, char **argv, char **argvtmp)
{
	int	c;

	c = 0;
	if (argc == 2)
	{
		argc = word_cnt(argv[1], ' ');
		argvtmp = ft_split(argv[1], ' ');
	}
	else
	{
		c = 1;
		while (c < argc)
		{
			argvtmp[c - 1] = argv[c];
			c++;
		}
	}
	return (argvtmp);
}

int	solveargc(int argc, char **argv)
{
	if (argc == 2)
		argc = word_cnt(argv[1], ' ');
	else
		argc = argc - 1;
	return (argc);
}

struct s_l	makelist(int argc, char **argvtmp, struct s_l list, struct s_minmax m)
{
	int cum;
	while (list.length < argc)
	{
		if (ft_atoi(argvtmp[list.length]) == '\0')
		{
			ft_printf("Error\n");
			list.list = NULL;
			return (list);
		}
		list.list[list.length] = ft_atoi(argvtmp[list.length]);
		if (list.list[list.length] > m.max)
			m.max = list.list[list.length];
		if (list.list[list.length] < m.min)
			m.min = list.list[list.length];
		list.length++;
	}
cum = 0;
  while (cum < list.length) {
    printf("%i ", list.list[cum]);
    cum++;
  }
  printf("\n");
	//list = addmin(list, m.min);
	if (checkrepetition(list) == NULL)
	{
		ft_printf("Error\n");
		list.list = NULL;
		return (list);
	}
	return (list);
}

void	freeboth(int *list, char **argvtmp)
{
	free (list);
	free (argvtmp);
}
