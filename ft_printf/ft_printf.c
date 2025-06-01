/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:42:44 by babe              #+#    #+#             */
/*   Updated: 2025/06/01 21:05:24 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar(va_list *args)
{
    char    c;
    
    c = (char)va_arg(*args, int);
    write(1, &c, 1);
    return ;
}

static void ft_putstr(va_list *args)
{
    char    *s;
    
    s = va_arg(*args, char *);
    while (*s != '\0')
    {
        write(1, s, 1);
        s++;
    }
    return ;
}

static void ft_putpercent(void)
{
    write(1, "%", 1);
    return ;   
}

static void ft_frag_check(const char *format, va_list *args)
{
    if (format[0] == '%' && format[1] == 'c')
        ft_putchar(args);
    else if(format[0] == '%' && format[1] == 's')
        ft_putstr(args);
    else if(format[0] == '%' && format[1] == '%')
        ft_putpercent();
    return ;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;

    va_start(args, format);
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            ft_frag_check(&format[i], &args);
            i += 2;
        }
        else
        {
            write(1, &format[i], 1);
            i++;
        }
    }
    va_end(args);
    return (0);
}        


#include <stdio.h>

int main(void)
{
	char        c = 'A';
	char		*str = "Hello, World!";
	// void		*ptr = str;
	// int			decimal = -123;
	// int			integer = 456;
	// unsigned	u = 3000000000U;
	// int			hex_num = 255;

    ft_printf("%%c: %c\n", c);
	printf("%%c: %c\n\n", c);  //%c: A
    
    ft_printf("%%s: %s\n", str);
	printf("%%s: %s\n\n", str);  //%s: Hello, World!
    
    // ft_printf("%%p: %p\n", ptr);
	// printf("%%p: %p\n\n", ptr);  //%p: 0x1050e381e
    
	// ft_printf("%%d: %d\n", decimal);
	// printf("%%d: %d\n\n", decimal); //%d: -123
    
    // ft_printf("%%i: %i\n", integer);
    // printf("%%i: %i\n\n", integer);  //%i: 456
    
	// ft_printf("%%u: %u\n", u);
	// printf("%%u: %u\n\n", u);  //%u: 3000000000
    
	// ft_printf("%%x: %x\n", hex_num);
	// printf("%%x: %x\n\n", hex_num);  //%x: ff
    
    // ft_printf("%%X: %X\n", hex_num);
	// printf("%%X: %X\n\n", hex_num);  //%X: FF
    
    ft_printf("%%%%: %%\n");
	printf("%%%%: %%\n");  //%%: %

	return (0);
}
