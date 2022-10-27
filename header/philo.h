/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:56:10 by wprintes          #+#    #+#             */
/*   Updated: 2022/10/27 21:48:28 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_geral
{
	pthread_t		alive;
	pthread_mutex_t	*forks;
	int				total_fork;
	_Atomic int		death;
	_Atomic int		all_full;
	int				m_eat;
	int				exit;
	time_t			t_sleep;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_init;
	pthread_mutex_t	lock;
}	t_geral;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat;
	t_geral			*geral;
	time_t			last_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}	t_philo;

long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(char *c);
void	all_philos(int c_philos, t_philo *philos, t_geral *geral);
void	init_geral(t_geral *geral, char **argv);
time_t	current_time(void);
time_t	passed_time(t_geral *geral);
void	*philo_core(void *parameter);
void	*alive_func(void *parameter);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	eat(t_philo *philo);
void	sleep_think(t_philo *philo);
void	show_info(t_philo *philo, char *type);

#endif