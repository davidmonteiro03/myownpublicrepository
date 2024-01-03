/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 15:51:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_move_player(t_cub *cub, double x, double y)
{
	cub_small_check(cub, x, y);
	if (!cub->keys.right && !cub->keys.left)
		usleep(10000);
}

int	cub_press_key(int keycode, t_cub *cub)
{
	if (keycode == XK_Right)
		cub->keys.right = true;
	else if (keycode == XK_Left)
		cub->keys.left = true;
	else if (keycode == XK_w)
		cub->keys.w = true;
	else if (keycode == XK_s)
		cub->keys.s = true;
	else if (keycode == XK_a)
		cub->keys.a = true;
	else if (keycode == XK_d)
		cub->keys.d = true;
	else if (keycode == XK_Escape)
		cub_exit(cub);
	return (0);
}

int	cub_release_key(int keycode, t_cub *cub)
{
	if (keycode == XK_Right)
		cub->keys.right = false;
	else if (keycode == XK_Left)
		cub->keys.left = false;
	else if (keycode == XK_w)
		cub->keys.w = false;
	else if (keycode == XK_s)
		cub->keys.s = false;
	else if (keycode == XK_a)
		cub->keys.a = false;
	else if (keycode == XK_d)
		cub->keys.d = false;
	return (0);
}

int	cub_mouse_handler(int keycode, t_cub *cub)
{
	(void)cub;
	if (keycode == 1)
		printf("Shoooooooooooooooooot\n");
	return (0);
}

int	cub_render(t_cub *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx.mlx, cub->mlx.win, &x, &y);
	cub_check_keys(cub);
	return (0);
}