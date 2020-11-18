/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatnumber.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:00:59 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 16:01:01 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATNUMBER_H
# define FLOATNUMBER_H

# define MASK_EXP 0x7fff
# define MASK_EXP_SHIFT 0x3fff
# define MASK_SIGN 0x8000
# define LENGTH_ARRAY 280
# define BASE 1000000000000000000
# define LBASE 1000000000

typedef struct			s_float_number {
	unsigned long long	mnts;
	int					exp;
	unsigned char		sign;
}						t_fnum;

int						ft_bgi_length(unsigned long long *bgi);
void					ft_bgi_round(unsigned long long *bgi);
void					ft_get_number(t_fnum *fn, long double ld, \
										unsigned long long *hf);
t_fnum					*ft_fnum_new(void);
int						ft_part_integer(unsigned long long hf, int exp, \
										unsigned long long *bgi);
void					ft_bigint_addition(unsigned long long *bgi, \
							unsigned long long *p, unsigned long long *res);
void					ft_bigint_a_addition(unsigned long long *a, \
												unsigned long long *b);
void					ft_bigint_multi(unsigned long long *a, \
							unsigned long long *b, unsigned long long *res);
void					ft_multi_b_norme(unsigned long long *res, int j);
void					ft_bigint_copy(unsigned long long *a, \
										unsigned long long *b);
void					ft_bigint_a_multi(unsigned long long *a, \
								unsigned long long *b);
void					ft_bigint_print(unsigned long long *bgi);
int						ft_frc_print(unsigned long long *frc, int p, char sh);
int						ft_part_fraction(unsigned long long hf, int exp, \
											unsigned long long *frc);
int						ft_rounding(unsigned long long *a, int p, int bgi);
void					ft_bg_putllu_18(unsigned long long n);
void					ft_frc_putllu_n(unsigned long long n, int len);
void					ft_piece_int(unsigned long long *p, unsigned int pow);
void					ft_frc_a_addition(unsigned long long *a, \
								unsigned long long *b);

#endif
