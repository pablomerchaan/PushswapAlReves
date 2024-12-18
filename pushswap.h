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
	long	min;
	long	max;
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
	long	*list;
	int	length;
	int	partition;
};

struct s_rots	minrot(struct s_rots rot1, struct s_rots rot2);
struct s_rots	check(long *list, int length, int partition, int idx);
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
struct s_l		maketmpl(struct s_l list, struct s_rots rot, int sw);
struct s_l		completetmpl(struct s_l tmpl, struct s_l list);
long				*transformrot(struct s_l list, struct s_rots rot);
struct s_l	addmin(struct s_l list, int min);
int				lookahead(struct s_l list, struct s_rots rot,
					double current_min, int depth);
int				get_next(long *list, int partition, int num);
int				ft_atoi(const char *str);
int				sq(int c);
long				*checkrepetition(struct s_l list);
long				*transform(long *list, struct s_change actual, int length);
long				*transform_sa(long *list, int idx);
long				*transform_sb(long *list, int idx);
long				*transform_ss(long *list, int idx);
long				*transform_ra(long *list, int idx, int length);
long				*transform_rb(long *list, int idx);
long				*transform_rr(long *list, int idx, int length);
long				*transform_rra(long *list, int idx, int length);
long				*transform_rrb(long *list, int idx);
long				*transform_rrr(long *list, int idx, int length);
int				rotations(long *list, long min, long max, int length);
int				ft_printf(const char *str, ...);
int				ft_printp(va_list args, char c);
int				ft_putnbr(int nb);
int				ft_puthexa(unsigned int h, const char c, int count);
int				ft_putpointer(void *p);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putuint(unsigned int n);
int				ft_puthexaux(unsigned long long h, char c, int count);
int				sortthree(long *list, int length);
int				sorted(long *list, int length);
int				howmany(char **argv);
int				word_cnt(const char *s, char c);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char	**solveargv(int argc, char **argv, char **argvtmp);
int	solveargc(int argc, char **argv);
struct s_l	makelist(int argc, char **argvtmp, struct s_l list, struct s_minmax m);
void	freeboth(long *list, char **argvtmp);
#endif
