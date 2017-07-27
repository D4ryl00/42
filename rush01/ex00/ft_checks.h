/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:56:13 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 22:01:52 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKS_H
# define FT_CHECKS_H

int	check_double_number(char *str, int size);
int	check_line(char *str);
int	is_ok_line(char **tab, int line, char nbr);
int	is_ok_row(char **tab, int row, char nbr);
int	is_ok_block(char **tab, int row, int line, char nbr);

#endif
