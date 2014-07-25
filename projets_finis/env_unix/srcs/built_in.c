/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 20:32:04 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/11 18:43:50 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>

int			ft_exit(char **split)
{
	int				len;

	len = table_len(split);
	if (len == 1)
		exit(0);
	else if (len == 2)
		exit(ft_atoi(split[1]));
	else
		ft_putendl_fd("exit: too many arguments", 2);
	return (127);
}

static void	ft_cd_env(void)
{
	char	buf[1024];
	char	*pwd;
	char	*cmd;
	char	**split;

	getcwd(buf, 1024);
	pwd = ft_getenv("PWD");
	if (pwd == NULL)
		pwd = buf;
	cmd = ft_strjoin("setenv OLDPWD ", pwd);
	split = ft_strsplit(cmd, ' ');
	ft_setenv(split);
	free(cmd);
	free_table(split);
	cmd = ft_strjoin("setenv PWD ", buf);
	split = ft_strsplit(cmd, ' ');
	ft_setenv(split);
	free(cmd);
	free_table(split);
}

static int	ft_cd_sub(char *path)
{
	struct stat		s;

	if (stat(path, &s) == -1)
	{
		ft_putstr_fd("cd: No such file or directory: ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	else if (s.st_mode & S_IXUSR)
		chdir(path);
	else
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	ft_cd_env();
	free(path);
	return (0);
}

int			ft_cd(char **split)
{
	char		*path;
	char		*tmp;

	if (table_len(split) == 1 && ((tmp = ft_getenv("HOME")) == NULL))
		return (ft_putendl_ret("cd: no home directory"));
	else if (table_len(split) == 1)
		path = ft_strdup(tmp);
	else if (table_len(split) == 2 && !ft_strcmp("-", split[1]))
	{
		if ((tmp = ft_getenv("OLDPWD")) == NULL)
			return (ft_putendl_ret("cd: no previous working directory"));
		path = ft_strdup(tmp);
	}
	else if (table_len(split) == 2 && '~' == split[1][0])
	{
		if ((tmp = ft_getenv("HOME")) == NULL)
			return (ft_putendl_ret("cd: no home directory"));
		path = ft_strjoin(tmp, &split[1][1]);
	}
	else if (table_len(split) == 2)
		path = ft_strdup(split[1]);
	else
		return (ft_putendl_ret("cd : too many arguments"));
	return (ft_cd_sub(path));
}

void		launch_cmd_sub(char **split, char *path)
{
	char		**p_split;
	char		*p;
	char		*buf;
	extern char	**environ;

	p_split = ft_strsplit(path, ':');
	p = ft_strjoin("/", split[0]);
	while (*p_split)
	{
		buf = ft_strjoin(*p_split, p);
		execve(buf, split, environ);
		p_split++;
		free(buf);
	}
	free(p);
}
