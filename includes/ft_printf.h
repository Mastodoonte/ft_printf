/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:32:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/06 10:02:07 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;
	int		type;
	int		star;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		minus;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		hexa;
	int		negative;
	int		spe_case;
	int		spe_string;
	int		spe_perc;
}	t_print;

void	ft_load_int(t_print *tab);
void	ft_load_uint(t_print *tab);
t_print	*ft_initialise_tab(t_print *tab);
t_print	*ft_initialise1_tab(t_print *tab);
int		ft_strchrpf(int lettre);
int		is_flag(char c);
int		is_format_specification(char c);
int		ft_printf(const char *format, ...);
int		ft_underpf(const char *format, t_print *tab);
int		ft_parsing_flag(const char *format, int i, t_print *tab);
int		ft_parsing(int c, t_print *tab);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb, t_print *tab);
void	ft_putchar(char c);
void	display(t_print *tab);
void	ft_putnbrpf(int nb, t_print *tab);
void	paddle_flags(t_print *tab, int num, int len);
void	ft_load_char(t_print *tab);
void	ft_load_string(t_print *tab);
int		ft_size_calculator(int nbr);
void	ft_process_specialwidth(t_print *tab, int size_num);
void	ft_process_width(t_print *tab, int size_num);
void	ft_process_prc(t_print *tab, int size_num);
void	ft_help_load(t_print *tab, int num, int size_num);
void	ft_help_load2(t_print *tab, int num, int size_num);
void	ft_load_pointer(t_print *tab);
void	ft_load_uint(t_print *tab);
void	ft_load_hexa(t_print *tab);
void	ft_load_percent(t_print *tab);
char	*ft_itoa_hex(unsigned int nb, char *hex_charset);
int		is_flag(char c);
int		is_format_specification(char c);
int		ft_is_digit(char c);
void	ft_minus_allocation(t_print *tab);
void	ft__width_star_allocation(t_print *tab);
void	ft_treat_noprc_nopnt(t_print *tab, int num, int size_num);
void	ft_under_noprcnopnt1(t_print *tab, int *num, int *size_num, int i);
void	ft_under_noprcnopnt2(t_print *tab, int *num, int *size_num);
void	ft_under_prc_pnt1(t_print *tab, int *num);
void	ft_under_prc_pnt2(t_print *tab, int *num, int *size_num);
void	ft_under_prc_pnt3(t_print *tab, int *size_num);
void	ft_process_prc(t_print *tab, int size_num);
void	ft_help_load(t_print *tab, int num, int size_num);
void	ft_putnbrpf(int nb, t_print *tab);
void	ft_under_load_int1prcunder0(t_print *tab, int *num, int *size_num);
void	ft_under_load_int2prcunder0(t_print *tab, int *num, int *size_num);
void	ft_under_load_int3prcunder0(t_print *tab, int *num, int *size_num);
void	ft_under_load_int1prcunder0_minus(t_print *tab, int *n, int *s_n);
void	ft_prcless0(t_print *tab, int num, int size_num);
void	ft_process_specialwidth(t_print *tab, int size_num);
void	ft_process_width(t_print *tab, int size_num);
void	ft_process_widths(t_print *tab);
void	ft_putstr(char *str, t_print *tab, int max);
int		ft_strlen(char *str);
void	ft_interuptor0_2(t_print *tab, int *size_str, char *output);
void	ft_interuptor0_3(t_print *tab, int *size_str, char *output);
void	ft_interuptor0_4(t_print *tab, int *size_str, char *output);
void	ft_interuptor0_5(t_print *tab, int *size_str, char *output);
void	ft_interuptor0_6(t_print *tab, int *size_str, char *output);
void	ft_interuptor1_1(t_print *tab);
void	ft_interuptor1_2(t_print *tab, int *interuptor);
void	ft_interuptor1_3(t_print *tab);
void	ft_interuptor1_4(t_print *tab, int *interuptor);
void	ft_putnbrpfu(unsigned int nb, t_print *tab);
int		ft_size_calculatoru(unsigned int nbr);
void	ft_process_widthu(t_print *tab, int size_num);
void	ft_process_specialwidthu(t_print *tab, int size_num);
void	ft_treat_noprc_nopntu(t_print *tab, unsigned int num, int size_num);
void	ft_noprc1_pntu(t_print *tab, unsigned int *num, int a);
void	ft_noprc2_pntu(t_print *tab, int *size_num);
void	ft_process_prcu(t_print *tab, int size_num);
void	ft_help_loadu(t_print *tab, unsigned int num, int size_num);
void	ft_under1_noprc_nopntu(t_print *tab, unsigned int *num, int a);
void	ft_under2_noprc_nopntu(t_print *tab, int *s_n, unsigned int *n);
void	ft_under3_noprc_nopntu(t_print *tab, int *size_num);
void	ft_interuptor0_1(t_print *tab, int *size_str, char *output);
void	ft_help_interuptor0_5(t_print *tab, int *size_str, char *output);
void	ft_putnbrpfx(unsigned int nb, t_print *tab);
void	x_dispatch1(t_print *tab, int size_num, unsigned int num);
void	x_dispatch2(t_print *tab, int size_num, unsigned int num);
void	x_dispatch3(t_print *tab, int size_num, unsigned int num);
void	x_dispatch4(t_print *tab, int size_num, unsigned int num);
void	x_dispatch5(t_print *tab, int size_num, unsigned int num);
void	ft_size_calculatorx(unsigned int nbr, t_print *tab);
void	ft_process_specialwidthx(t_print *tab, int size_num);
void	ft_process_widthx(t_print *tab, int size_num);
void	ft_h_prc0_pnt0_minus1(t_print *tab, unsigned int *num, int *size_num);
void	ft_h_num_less0(t_print *tab, unsigned int *num);
void	ft_help_load2x(t_print *tab, unsigned int num, int size_num);
void	ft_help_loadx(t_print *tab, unsigned int num, int size_num);
void	ft_process_prcx(t_print *tab, int size_num);
void	x_dispatch6(t_print *tab, int size_num, unsigned int num);
void	ft_h_pnt1_prcless0(t_print *tab, int *s_n, unsigned int *n, int a);
void	ft_h_minus0_pnt1(t_print *tab, int *size_num);
void	ft_h_minus1_pnt1(t_print *tab, unsigned int *num, int *size_num);
void	ft_h_prc0_pnt0_minus0(t_print *tab, int *size_num);
void	x_first_dispatch(t_print *tab, int size_num, unsigned int num);
void	ft_load_hexa(t_print *tab);
void	ft_size_calculatorp(unsigned long int nbr, t_print *tab);
void	ft_putnbrpfp(unsigned long int nb, t_print *tab);
void	ft_process_widthp(t_print *tab);
void	ft_display(unsigned long int pointer, t_print *tab);
void	ft_help_load_pointer(unsigned long int pointer, t_print *tab);
void	ft_display_more_wdt( t_print *tab, int a);
void	p_pnt1_2(t_print *tab, unsigned long int s_p, unsigned long int p);
void	p_pnt1(t_print *tab, unsigned long int pointer);
void	ft_udr_dsptch(t_print *t, unsigned long int p, unsigned long int s_p);
void	ft_h_dsptch(t_print *t, unsigned long int p, unsigned long int s_p);
void	ft_dispatch_p_1(t_print *t, unsigned long int p, unsigned long int s_p);
void	ft_dispatch_p_2(t_print *tab, unsigned long int size_pointer);
void	ft_spe_p1(t_print *tab, unsigned long int s_p, unsigned long int p);
void	ft_spe_p2(t_print *tab, unsigned long int s_p, unsigned long int p);
void	ft_spe_p3(t_print *tab, unsigned long int s_p, unsigned long int p);
void	ft_spe_p4(t_print *tab);
void	ft_spe_p5(t_print *tab, unsigned long int s_p, unsigned long int p);
void	ft_help_spe1_p4(t_print *tab, int a);
void	ft_help_spe_p4(t_print *tab, int a);
void	ft_h_spe1_p2(t_print *tab, unsigned long int s_p, unsigned long int p);

#endif
