/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:26:33 by camilla           #+#    #+#             */
/*   Updated: 2020/04/09 20:33:53 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/includes/ft_printf.h"
#include "ft_printf/libft/includes/libft.h"
#include <stdio.h>
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

void	launch(void)
{
	pid_t	pid;
	char	*executable;

	pid = fork();
	executable = "resources/players/cleisti.filler";
	if (pid == 0)
		execl("resources/players/cleisti.filler", NULL);
	else
		waitpid(pid,0,0);
}

void	player(void)
{
	FILE	*fptr;
	char	*filename;
	char	c;
	char	size[2];

	filename = "testerfiles/playerinfo";
	fptr = fopen(filename, "r");
	if (!fptr)
	{
		ft_printf("Cannot open file\n");
		exit(0);
	}
	c = fgetc(fptr);
	launch();
	while (c != EOF)
	{
		ft_printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
}

void	map(void)
{
	FILE	*fptr;
	char	*filename;
	char	c;
	char	size[2];

	ft_printf("map-size [choose]: XS, S, M, L ? ");
	scanf("%s", size);
	if (ft_strcmp(size, "XS") == 0)
		filename = "resources/maps/map03";
	else if (ft_strcmp(size, "S") == 0)
		filename = "resources/maps/map00";
	else if (ft_strcmp(size, "M") == 0)
		filename = "resources/maps/map01";
	else if (ft_strcmp(size, "L") == 0)
		filename = "resources/maps/map03";
	if (!filename)
		exit(0);
	ft_printf("Map %s\n", size);
	fptr = fopen(filename, "r");
	if (!fptr)
	{
		ft_printf("Cannot open file\n");
		exit(0);
	}
	c = fgetc(fptr);
	while (c != EOF)
	{
		ft_printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
}

void	token(void)
{
	FILE	*fptr;
	char	*filename;
	char	c;
	char	size[3];
	
	ft_printf("token [choose]: '1-2', '1-3', '3-6', '3-8' ? ");
	scanf("%s", size);
	if (ft_strcmp(size, "1-2") == 0)
		filename = "testerfiles/token-1-2";
	else if (ft_strcmp(size, "1-3") == 0)
		filename = "testerfiles/token-1-3";
	else if (ft_strcmp(size, "3-6") == 0)
		filename = "testerfiles/token-3-6";
	else if (ft_strcmp(size, "3-8") == 0)
		filename = "testerfiles/token-3-8";
	if (!filename)
		exit(0);
	ft_printf("Token %s\n", size);
	fptr = fopen(filename, "r");
	if (!fptr)
	{
		ft_printf("Cannot open file\n");
		return ;
	}
	c = fgetc(fptr);
	while (c != EOF)
	{
		ft_printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
	
}

int		main(int argc, char **argv)
{
	char arg[1];

	if (argc < 2)
	{
		ft_printf("Give argument: ");
		scanf("%1s", arg);
	}
	else if (argc > 2)
	{
		ft_printf("Too many arguments. Give only 1. ");
		scanf("%1s", arg);
	}
	else
		arg[0] = argv[1][0];
	while (1)
	{
		if (ft_atoi(arg) > 0 && ft_atoi(arg) < 4)
		{
			if (ft_atoi(arg) == 1)
				player();
			if (ft_atoi(arg) == 2)
				map();
			else if (ft_atoi(arg) == 3)
				token();
			arg[0] = '\0';
		}
		else
		{
			ft_printf("Give argument.\n'1' for player info.\n'2' for map.\n'3' for token.\n");
			scanf("%s", arg);
		}
	}
	return (0);
}