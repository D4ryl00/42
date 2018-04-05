/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:40:09 by rbarbero          #+#    #+#             */
/*   Updated: 2018/03/29 07:15:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "time.h"

int	sort_by_access_time(t_list *l1, t_list *l2)
{
	time_t	time1;
	time_t	time2;

	time1 = ((t_file *)l1->content)->stats->st_atime;
	time2 = ((t_file *)l2->content)->stats->st_atime;
	if (time1 == time2)
		return (sort_by_name(l1, l2));
	return ((int)time2 - (int)time1);
}

int	sort_by_modif_time(t_list *l1, t_list *l2)
{
	time_t	time1;
	time_t	time2;

	time1 = ((t_file *)l1->content)->stats->st_mtime;
	time2 = ((t_file *)l2->content)->stats->st_mtime;
	if (time1 == time2)
		return (sort_by_name(l1, l2));
	return ((int)time2 - (int)time1);
}

int	sort_by_name(t_list *l1, t_list *l2)
{
	return (ft_strcmp(((t_file *)l1->content)->name
				, ((t_file *)l2->content)->name));
}
