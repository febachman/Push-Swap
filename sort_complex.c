int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

chunk_size = (sqrt * 15 / 10) + (total_size / 100);

int	rank_convert(t_stack *a)
{
	int stack_size;
	int i;
	int *array_sorted;
	t_node *current;

	stack_size = a->size;

	array_sorted = malloc(stack_size * sizeof(int));

	if (!array_sorted)
		return (1);

	current = a->head;
	i = 0;

	while (i < stack_size)
	{
		array_sorted[i] = current->value;
		current = current->next;
		i++;
	}

	current = a->head;
	i = 0;
	free(array_sorted);
	return (0);
}

// rank_convert(a):

//     tamanho = a->size

//     criar array

//     copiar valores da stack A para o array

//     ordenar o array

//     para cada node da stack A:
//         procurar o valor do node dentro do array ordenado
//         trocar o valor do node pela posição encontrada

//     liberar array

