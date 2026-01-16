/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:14:57 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/16 03:51:35 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

int	ft_puthexa_fd(unsigned int n, int fd);
int	ft_puthexa_caps_fd(unsigned int n, int fd);
int	ft_puthexa_caps_fd(unsigned int n, int fd);
int	ft_putpointer(void *pointer, int fd);
int	ft_printf(const char *fixed_flags, ...);

#endif
