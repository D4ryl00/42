void	ft_putchar(char c);

void	print_char_to_hex(unsigned char addr, unsigned int digits)
{
	if (digits > 1)
		print_char_to_hex(addr / 16, digits - 1);
	ft_putchar(addr % 16 >= 10 ? addr % 16 - 10 + 'a' : addr % 16 + '0');
}

void	print_hex_value(unsigned char *addr, unsigned int start, unsigned int end)
{
	unsigned int	max;

	max = start + 16;
	while (start < max && start < end)
	{
		if (!(start % 2))
			ft_putchar(' ');
		print_char_to_hex(addr[start], 2);
		start++;
	}
	while (start < max)
	{
		if (!(start % 2))
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		start++;
	}
}

void	print_ascii_value(unsigned char *addr, unsigned int start, unsigned int end)
{
	unsigned int	max;

	max = start + 16;
	while (start < max && start < end)
	{
		ft_putchar(addr[start] > 31 && addr[start] < 127 ? addr[start] : '.');
		start++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_char_to_hex(i, 8);
		ft_putchar(':');
		print_hex_value(ptr, i, size);
		ft_putchar(' ');
		print_ascii_value(ptr, i, size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
