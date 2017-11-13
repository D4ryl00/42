/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 20:32:57 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/25 14:12:34 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "board.h"

void	ft_putchar(char c);
void	print_matrix(t_board *board);
void	print_int_matrix(t_int_board *res);
void	ft_putnbr(int nb);
void	ft_putnstr(char *str, int n);
void	print_result(t_board *board, t_coord *corner_rb);

#endif
