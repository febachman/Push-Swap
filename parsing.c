/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:49:10 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/27 14:49:13 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

/*
	Fluxo geral do parsing:

	1. Criar configuração padrão:
		- strategy = ADAPTIVE
		- bench = false

	2. Percorrer argv a partir de argv[1]

	3. Se encontrar uma flag:
		- atualizar a config

	4. Se encontrar número ou string com números:
		- separar tokens
		- validar cada token
		- guardar na stack A

	5. Depois de tudo:
		- verificar duplicados
		- aplicar estratégia
*/

/*
	Enum que representa as estratégias possíveis do programa.
	ERROR é usado apenas para indicar uma flag de estratégia inválida.
*/
typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	ADAPTIVE,
	COMPLEX,
	ERROR
}	t_strategy;

/*
	Estrutura que guarda as configurações de parsing.

	strategy:
		define qual algoritmo será usado.

	bench:
		define se o modo benchmark está ativo ou não.
*/
typedef struct s_parsing
{
	t_strategy	strategy;
	bool		bench;
}	t_parsing;

/*
	Funções externas esperadas no seu projeto.

	Você precisa adaptar esses nomes conforme sua libft/lista.
*/
typedef struct s_dlist	t_dlist;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);

int		is_valid_number(char *str);
int		ft_atol_checked(char *str, int *out);
int		has_duplicate(t_dlist *a);

void	stack_add_back(t_dlist **a, int value);
void	destroy_lst(t_dlist **lst);

int		apply_strategy(t_parsing *parsing, t_dlist *a);

/*
	Cria a configuração padrão do programa.

	Por padrão:
	- estratégia ADAPTIVE
	- benchmark desativado
*/
void	default_config(t_parsing *parsing)
{
	parsing->strategy = ADAPTIVE;
	parsing->bench = false;
}

/*
	Verifica se o argumento é uma flag de estratégia.

	Retornos:
	1  -> era uma flag de estratégia válida
	-1 -> parecia uma flag de estratégia, mas é inválida
	0  -> não é flag de estratégia

	Exemplos válidos:
	--simple
	--medium
	--complex
	--adaptive
*/
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

	/*
		Se começa com "--", provavelmente é uma flag inválida.
		Exemplo: --teste
	*/
	if (arg[0] == '-' && arg[1] == '-')
		return (-1);

	return (0);
}

/*
	Verifica se o argumento é a flag de benchmark.

	Retornos:
	1 -> era --bench
	0 -> não era --bench
*/
int	is_bench_flag(char *arg, t_parsing *parsing)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		parsing->bench = true;
		return (1);
	}
	return (0);
}

/*
	Verifica se o argumento é alguma flag conhecida.

	Retornos:
	1  -> era flag válida
	-1 -> era flag inválida
	0  -> não era flag, então deve ser tratado como número/string de números
*/
int	parse_flag(char *arg, t_parsing *parsing)
{
	int	result;

	result = is_strategy_flag(arg, parsing);
	if (result == 1)
		return (1);
	if (result == -1)
		return (-1);

	if (is_bench_flag(arg, parsing))
		return (1);

	return (0);
}

/*
	Valida e adiciona um único token numérico na stack A.

	Exemplos válidos:
	"42"
	"-10"
	"+7"

	Exemplos inválidos:
	"--1"
	"abc"
	"12a"
	"999999999999999999999"
*/
int	parse_number_token(char *token, t_dlist **a)
{
	int	value;

	if (!is_valid_number(token))
		return (1);

	if (ft_atol_checked(token, &value))
		return (1);

	stack_add_back(a, value);
	return (0);
}

/*
	Recebe uma string que pode conter um ou vários números.

	Exemplos:
	argv[i] = "42"
	argv[i] = "3 2 1"
	argv[i] = "-5 10 +7"

	A função separa por espaço, valida cada token e adiciona na stack A.
*/
int	parse_number_arg(char *arg, t_dlist **a)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (1);

	i = 0;
	while (tokens[i])
	{
		if (parse_number_token(tokens[i], a))
		{
			ft_free_split(tokens);
			return (1);
		}
		i++;
	}

	ft_free_split(tokens);
	return (0);
}

/*
	Função principal de parsing.

	Responsabilidades:
	- inicializar a stack A como NULL
	- percorrer argv
	- identificar flags
	- identificar números
	- preencher a stack A
	- verificar duplicados no final

	Retorno:
	NULL -> erro de parsing
	stack A preenchida -> sucesso
*/
t_dlist	*ft_parse_args(int argc, char **argv, t_parsing *parsing)
{
	t_dlist	*a;
	int		i;
	int		flag_result;

	a = NULL;
	i = 1;

	while (i < argc)
	{
		flag_result = parse_flag(argv[i], parsing);

		if (flag_result == -1)
		{
			destroy_lst(&a);
			return (NULL);
		}

		/*
			Se flag_result == 1, o argumento era uma flag válida.
			Então não tentamos interpretar como número.
		*/
		if (flag_result == 0)
		{
			if (parse_number_arg(argv[i], &a))
			{
				destroy_lst(&a);
				return (NULL);
			}
		}

		i++;
	}

	/*
		Depois de ler todos os argumentos, verificamos duplicados.

		Exemplo inválido:
		./push_swap 1 2 3 2
	*/
	if (has_duplicate(a))
	{
		destroy_lst(&a);
		return (NULL);
	}

	return (a);
}

/*
	Escolhe qual estratégia aplicar de acordo com a configuração.

	Essa função ainda depende das suas estratégias reais.
	Os nomes abaixo são apenas exemplos.
*/
int	apply_strategy(t_parsing *parsing, t_dlist *a)
{
	if (!parsing || !a)
		return (1);

	/*
		Exemplo de estrutura possível:

		if (stack_size(a) == 2)
			return (strategy_2(a));
		else if (stack_size(a) == 3)
			return (strategy_3(a));
		else if (stack_size(a) == 5)
			return (strategy_5(a));
	*/

	if (parsing->strategy == SIMPLE)
	{
		/*
			return (strategy_simple(a));
		*/
	}
	else if (parsing->strategy == MEDIUM)
	{
		/*
			return (strategy_medium(a));
		*/
	}
	else if (parsing->strategy == COMPLEX)
	{
		/*
			return (strategy_complex(a));
		*/
	}
	else if (parsing->strategy == ADAPTIVE)
	{
		/*
			return (strategy_adaptive(a));
		*/
	}

	return (0);
}

/*
	main:

	1. Verifica se existem argumentos suficientes.
	2. Cria configuração padrão.
	3. Faz parsing das flags e números.
	4. Se parsing falhar, imprime Error.
	5. Aplica a estratégia.
	6. Libera a lista.
*/
int	main(int argc, char **argv)
{
	t_dlist		*a;
	t_parsing	parsing;

	if (argc < 2)
		return (0);

	default_config(&parsing);

	a = ft_parse_args(argc, argv, &parsing);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	if (apply_strategy(&parsing, a))
	{
		ft_putstr_fd("Error\n", 2);
		destroy_lst(&a);
		return (1);
	}

	destroy_lst(&a);
	return (0);
}