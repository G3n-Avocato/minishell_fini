/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:50:18 by gbertet           #+#    #+#             */
/*   Updated: 2023/06/27 15:06:02 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_echo_arg(char *s)
// {
// 	char	first_quote;
// 	int		j;

// 	j = 0;
// 	first_quote = '\0';
// 	while (s[j])
// 	{
// 		if ((s[j] == '\'' || s[j] == '\"') && first_quote == '\0')
// 			first_quote = s[j];
// 		else if (s[j] != first_quote)
// 			write(1, &s[j], 1);
// 		j++;
// 	}
// }

int	is_newline(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (s[i++] == '-')
	{
		while (s[i] == 'n')
		{
			i++;
			res = 1;
		}
		if (s[i])
			return (0);
		return (res);
	}
	return (0);
}

int ft_echo(char **cmd)
{
	int i;
	int	nl;

	i = 1;
	nl = 1;
	if (!cmd[1])
	{
		printf("\n");
		return (0);
	}
	while (is_newline(cmd[i]))
	{
		nl = 0;
		if (!cmd[++i])
			break;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[++i])
			printf(" ");
	}
	if (nl)
		printf("\n");
	return (0);
}
