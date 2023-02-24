/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:13:03 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 19:02:13 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error_1(int n, char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (n == FD_ERROR)
	{
		free(s);
		ft_putstr_fd("OPEN ne s'est pas deroule correctement\n", 2);
	}
	else if (n == RD_ERROR)
	{
		free(s);
		ft_putstr_fd("READ ne s'est pas deroule correctement\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	ft_error_2(int n, char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (n == ARG_ERROR)
		ft_putstr_fd("merci de bien vouloir mettre 1 seul argument\n", 2);
	else if (n == EXT_ERROR)
		ft_putstr_fd("mauvaise extension\n", 2);
	else if (n == MAP_VOID)
	{
		free(s);
		ft_putstr_fd("la map est vide\n", 2);
	}
	else if (n == MAP_ERROR)
	{
		free(s);
		ft_putstr_fd("La map n'est pas exploitable\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	ft_error_3(int n, char *s, t_vars *vars)
{
	ft_putstr_fd("Error\n", 2);
	if (n == MAP_LETTER_ERROR)
	{
		ft_free_tab_char(vars->map_split);
		free(s);
		ft_putstr_fd("les carateres autorises sont : 0, 1, C, E, P, B\n", 2);
	}
	else if (n == LETTER_E_P_ERROR)
	{
		ft_free_tab_char(vars->map_split);
		free(s);
		ft_putstr_fd("1 seul Player || 1 seule sortie est requis(e)\n", 2);
	}
	else if (n == LETTER_C_ERROR)
	{
		ft_free_tab_char(vars->map_split);
		free(s);
		ft_putstr_fd("1 item est requis au minimum\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	ft_error_4(int n)
{
	ft_putstr_fd("Error\n", 2);
	if (n == SIZE_ERROR)
		ft_putstr_fd("ce n'est pas un rectangle\n", 2);
	else if (n == COLUMN_ERROR)
		ft_putstr_fd("les colonnes sont minimum de 3\n", 2);
	else if (n == LINE_ERROR)
		ft_putstr_fd("les lines sont minimum de 3\n", 2);
	else if (n == WALLS_ERROR)
		ft_putstr_fd("les murs ne sont pas conformes\n", 2);
	exit(EXIT_FAILURE);
}
