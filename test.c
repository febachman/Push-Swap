#include <stdbool.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}				t_strategy;

typedef struct s_parsing
{
	t_strategy	strategy;
	bool		bench;
}				t_parsing;

void	default_config(t_parsing *parsing)
{
	parsing->strategy = ADAPTIVE;
	parsing->bench = false;
}

int	is_strategy_flag(char *arg, t_parsing *parsing)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		parsing->strategy = SIMPLE;
		return (1);
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		parsing->strategy = MEDIUM;
		return (1);
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		parsing->strategy = COMPLEX;
		return (1);
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		parsing->strategy = ADAPTIVE;
		return (1);
	}
	return (0);
}

int	is_bench_flag(char *arg, t_parsing *parsing)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		parsing->bench = true;
		return (1);
	}
	return (0);
}

int	is_flag(char *arg, t_parsing *parsing)
{
	if (is_strategy_flag(arg, parsing))
		return (1);
	if (is_bench_flag(arg, parsing))
		return (1);
	if (arg[0] == '-' && arg[1] == '-')
		return (-1);
	return (0);
}

