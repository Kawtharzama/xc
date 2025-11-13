/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:55:12 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:55:16 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *s, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long int p, char c);
int		ft_unsigned_putnbr(unsigned int nbr);
int		ft_puthex(unsigned int num, char c);
char	*ft_itoa(int n);

#endif
