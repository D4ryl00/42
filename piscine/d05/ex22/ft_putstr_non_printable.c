void	ft_putchar(char c);

void	print_char_to_hex(char c)
{
	ft_putchar('\\');
	ft_putchar(c / 16 < 10 ? c / 16 + '0' : c / 16 - 10 + 'a');
	ft_putchar(c % 16 < 10 ? c % 16 + '0' : c % 16 - 10 + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str == 127)
			print_char_to_hex(*str);
		else
			ft_putchar(*str);
		str++;
	}
}
