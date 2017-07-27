//
// Created by Remi BARBERO on 7/23/17.
//

#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    int power;
    int tmp;

    tmp = nb;
    power = 1;
    while (tmp /= 10)
    {
        power *= 10;
    }
    if (nb < 0)
    {
        ft_putchar('-');
    }
    else
    {
        nb = -nb;
    }
    while (power)
    {
        ft_putchar(-((nb / power) % 10) + '0');
        power /= 10;
    }
}