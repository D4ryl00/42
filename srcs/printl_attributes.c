/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printl_attributes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:42:39 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:56:41 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/acl.h>
#include <sys/xattr.h>

char	get_file_type(struct stat *stats)
{
	if (S_ISBLK(stats->st_mode))
		return ('b');
	else if (S_ISCHR(stats->st_mode))
		return ('c');
	else if (S_ISDIR(stats->st_mode))
		return ('d');
	else if (S_ISLNK(stats->st_mode))
		return ('l');
	else if (S_ISSOCK(stats->st_mode))
		return ('s');
	else if (S_ISFIFO(stats->st_mode))
		return ('p');
	else
		return ('-');
}

char	get_file_ext_attr(char *path)
{
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	if (acl_get_file(path, ACL_TYPE_EXTENDED))
		return ('+');
	return (' ');
}

char	*get_uname(struct stat *stat)
{
	struct passwd	*pw;

	if (!(pw = getpwuid(stat->st_uid)))
		return (NULL);
	return (pw->pw_name);
}

char	*get_gname(struct stat *stat)
{
	struct group	*group;

	if (!(group = getgrgid(stat->st_gid)))
		return (NULL);
	return (group->gr_name);
}
