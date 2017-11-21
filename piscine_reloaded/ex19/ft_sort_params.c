/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:24:03 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/08 15:49:13 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(void *a, void *b)
{
	void	*tmp;

	tmp = *(void **)a;
	*(void **)a = *(void **)b;
	*(void **)b = tmp;
}

void	ft_sort(char **arr, int size)
{
	int	i;
	int	greater;

	if (size < 2)
		return ;
	i = 0;
	greater = 0;
	while (++i < size)
		if (ft_strcmp(arr[greater], arr[i]) < 0)
			greater = i;
	ft_swap(&arr[greater], &arr[size - 1]);
	ft_sort(arr, size - 1);
}

int		main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	ft_sort(argv + 1, argc - 1);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			ft_putchar(argv[i][j]);
		ft_putchar('\n');
	}
	return (0);
}
