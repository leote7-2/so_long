/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:06:24 by joaoleote         #+#    #+#             */
/*   Updated: 2025/03/12 16:40:01 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	safe_exit(t_d *d, int exit_code)
{
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	if (d->assets.coins_existance)
		free(d->assets.coins_existance);
	if (d->assets.c_pos)
		free(d->assets.c_pos);
	if (d->assets.enemies_pos)
		free(d->assets.enemies_pos);
	if (d->map.mtx || d->map.mtx_copy)
		clean_matrix(d);
	exit(exit_code);
}

void	init_and_run_game(t_d *d)
{
	initializer(d);
	background(d);
	mlx_loop_hook(d->mlx, combined_render, d);
	mlx_hook(d->win, 2, 1L << 0, key_press, d);
	mlx_hook(d->win, 17, 0, close_window, d);
	mlx_loop(d->mlx);
}

int	main(int argc, char **argv)
{
	t_d	d;
	int	coins;
	int	enemys;

	struct_init(&d);
	d.map.name = argv[1];
	if (argc < 2)
		d.map.name = "";
	arg_checker(argc, &d);
	map_x_y_helper(argv[1], &d);
	map_x_y(argv[1], &d);
	bounderies_checker(&d);
	coins = d.assets.coin;
	enemys = d.assets.enemy;
	flood_fill(&d, d.assets.p_pos.x, d.assets.p_pos.y);
	if (d.assets.coin != 0 || d.map.exit_found != 1)
		error_handler(3, &d);
	d.assets.coin = coins;
	d.assets.enemy = enemys;
	init_and_run_game(&d);
	return (free_all(&d), 0);
}
