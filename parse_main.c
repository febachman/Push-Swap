/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/03 10:51:01 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*TODO: TRABALHAR NA MAIN:
iniciar stack a
iniciar parsing config
se argc == 1: sair sem imprimir nada
chamar parse_args
se der erro: limpar stack + imprimir Error*/

int	parse_args(int argc, char **argv, t_stack *a, t_parsing *parsing)
{
	int	i;
	int	flag_result;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (1);
		parse_flag(argv[i], parsing)
		// se não for flag, tentar número
		i++;
	}
	// verificar se viu número
	return (0);
}