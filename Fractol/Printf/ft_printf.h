/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:06 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:12:24 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	is_x(unsigned int x);
int	is_x_upper(unsigned int X);
int	is_str(char *str);
int	is_char(int c);
int	is_ptr(void *ptr);
int	is_dec(int nb);
int	is_int(int nb);
int	is_uns(unsigned int nb);

#endif
