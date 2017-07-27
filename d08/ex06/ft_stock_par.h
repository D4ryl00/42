/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:47:07 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/17 23:19:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tab;
}					t_stock_par;

void				ft_putchar(char c);
char				**ft_split_whitespaces(char *str);
void				ft_show_tab(struct s_stock_par *par);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
void				add_arg(t_stock_par *tab, char **av, int i);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif
