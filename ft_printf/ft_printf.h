/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:55:14 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/04 18:16:17 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putchar_pourcent(void);
int		ft_puthexa(int n);
int		ft_puthexa2(int n);
int		ft_putnbr(int n);
int		ft_unputnbr( unsigned int n);
int		ft_puthexa_p(void *n);
int		ft_printf_s(char *s);

#endif
