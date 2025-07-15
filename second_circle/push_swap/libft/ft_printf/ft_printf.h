/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:51:52 by habe              #+#    #+#             */
/*   Updated: 2025/07/14 15:49:13 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(va_list *args);
int	ft_putstr(va_list *args);
int	ft_putpercent(void);
int	ft_putptr(va_list *args);
int	ft_putnbr(va_list *args);
int	ft_putnbr_unsigned(va_list *args);
int	ft_put_lohex(va_list *args);
int	ft_put_uphex(va_list *args);

#endif
