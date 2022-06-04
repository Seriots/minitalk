/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:33:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 13:54:16 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H
# include "../ft_printf.h"
# define BASE_HEXA_MIN "0123456789abcdef"
# define BASE_HEXA_MAJ "0123456789ABCDEF"

/*ft_putchar.c*/
int		ft_check_putchar(t_arg elem, char c);
int		ft_check_flags_putchar(t_arg elem, char c, int print);
int		ft_putchar(char c, int print);

/*ft_putstr.c*/
int		ft_check_putstr(t_arg elem, char *s);
int		ft_check_flags_putstr(t_arg elem, char *s, int print);
int		ft_putstr(const char *s, t_arg elem, int print);

/*ft_putnbr.c*/
void	ft_check_flags_putnbr2(int *i, t_arg elem, int n, int print);
void	ft_check_flags_putnbr3(int *i, t_arg elem, int n, int print);
int		ft_check_putnbr(t_arg elem, int n);
int		ft_check_flags_putnbr(t_arg elem, int n, int print);
void	ft_putnbr(int n, int *i, int print);

/*ft_putnbr_unsigned.c*/
int		ft_check_putnbrunsigned(t_arg elem, unsigned int n);
int		ft_check_flags_putnbr_unsigned(t_arg elem, unsigned int n, int print);
void	ft_putnbr_unsigned(unsigned int n, int *i, int print);

/*ft_putpointeur.c*/
int		ft_check_putpointeur(t_arg elem, void *ptr);
void	ft_check_flags_putpointeur3(int *i, void *ptr, int print, t_arg elem);
void	ft_check_flags_putpointeur2(int *i, void *ptr, int print, t_arg elem);
int		ft_check_flags_putpointeur(t_arg elem, void	*ptr, int print);
void	ft_writepointeur(unsigned long addr, int *i, int print);
int		ft_putpointeur(void	*p, int print);

/*ft_puthexa_maj.c*/
int		ft_check_puthexa_maj(t_arg elem, unsigned int n);
void	ft_check_puthexa_maj2(int *i, t_arg elem, unsigned int n, int print);
int		ft_check_flags_puthexa_maj(t_arg elem, unsigned int n, int print);
void	ft_puthexa_maj(unsigned int n, int *i, int print);

/*ft_puthexa_min.c*/
int		ft_check_puthexa_min(t_arg elem, unsigned int n);
void	ft_check_puthexa_min2(int *i, t_arg elem, unsigned int n, int print);
int		ft_check_flags_puthexa_min(t_arg elem, unsigned int n, int print);
void	ft_puthexa_min(unsigned int n, int *i, int print);

#endif
