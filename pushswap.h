/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:58:52 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/16 15:12:06 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

enum e_type_of_change
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

struct s_minmax
{
	int	min;
	int	max;
};

struct s_intsaux
{
	int	i;
	int	good_cost;
	int	steps;
	int	current_max;
};

struct s_intslk
{
	int	i;
	int	cost;
	int	current_depth;
	int	current_cost;
	int	good_cost;
};

struct s_intsrot
{
	int	i;
	int	round;
	int	current_cost;
	int	steps;
	int	j;
};
struct s_change
{
	enum e_type_of_change	type;
	int						idx;
};

struct s_rots
{
	int	type;
	int	cost;
	int	idx;
	int	steps_a;
	int	steps_b;
};

struct s_l
{
	int	*list;
	int	length;
	int	partition;
};

struct s_rots	minrot(struct s_rots rot1, struct s_rots rot2);
struct s_rots	check(int *list, int length, int partition, int idx);
struct s_rots	lkaux1( double current_min, int depth,
					struct s_intslk intslk, struct s_l tmpl);
struct s_rots	auxaux(struct s_intsaux ints, struct s_l list,
					struct s_rots goodrot, int current_cost);
struct s_intslk	lkaux2( double current_min, int depth,
					struct s_intslk intslk, struct s_l tmpl);
struct s_intsaux	completeints(struct s_intsaux ints, struct s_l list, struct s_rots goodrot);
void			do_print(int type_1, int type_2, int comp_1, int comp_2);
void			emit_step(int type);
void			emit_from_rots(struct s_rots rot);
void			freeboth(int *list, char **argvtmp);
struct s_l		maketmpl(struct s_l list, struct s_rots rot, int sw);
struct s_l		completetmpl(struct s_l tmpl, struct s_l list);
struct s_l		makelist(int argc, char **argvtmp, struct s_l list, struct s_minmax m);
int				*transformrot(struct s_l list, struct s_rots rot);
int				lookahead(struct s_l list, struct s_rots rot,
					double current_min, int depth);
int				get_next(int *list, int partition, int num);
int				ft_atoi(const char *str);
int				sq(int c);
int				*convert(struct s_change prev, struct s_change actual);
int				*transform(int *list, struct s_change actual, int length);
int				*transform_sa(int *list, int idx);
int				*transform_sb(int *list, int idx);
int				*transform_ss(int *list, int idx);
int				*transform_ra(int *list, int idx, int length);
int				*transform_rb(int *list, int idx);
int				*transform_rr(int *list, int idx, int length);
int				*transform_rra(int *list, int idx, int length);
int				*transform_rrb(int *list, int idx);
int				*transform_rrr(int *list, int idx, int length);
int				*checkrepetition(struct s_l list);
int				rotations(int *list, int min, int max, int length);
int				solveargc(int argc, char **argv);
int				ft_printf(const char *str, ...);
int				ft_printp(va_list args, char c);
int				ft_putnbr(int nb);
int				ft_puthexa(unsigned int h, const char c, int count);
int				ft_putpointer(void *p);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putuint(unsigned int n);
int				ft_puthexaux(unsigned long long h, char c, int count);
int				sortthree(int *list, int length);
int				sorted(int *list, int length);
int				howmany(char **argv);
int				word_cnt(const char *s, char c);
char				**solveargv(int argc, char **argv, char **argvtmp);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
#endif
