/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:01:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 13:43:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_check_pixel(t_cub *cub, int x, int y, bool erase)
{
	mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
		cub->tmp.x + x, cub->tmp.y + y, 0x00FF00);
	if (!erase)
		return ;
	auto int pos_x = (int)((cub->player.x + x) / MMAP_SZ);
	auto int pos_y = (int)((cub->player.y + y) / MMAP_SZ);
	if (cub->map.map[pos_y][pos_x] == '1')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0xCCCCCC);
	else if (cub->map.map[pos_y][pos_x] == '0' || \
		cub->map.map[pos_y][pos_x] == ' ' || \
		cub->map.map[pos_y][pos_x] == cub->player.c)
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0x666666);
	else if (cub->map.map[pos_y][pos_x] == '-')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0x333333);
}

void	cub_draw_player(t_cub *cub, bool erase)
{
/* 	auto int i = -1;
	while (++i < PLAYER_SZ)
	{
		auto int j = PLAYER_SZ * -1 - 1;
		while (++j <= PLAYER_SZ)
			printf("*");
		printf("\n");
	} */
	cub_check_pixel(cub, 0, 0, erase);
}

void	cub_small_check(t_cub *cub, double x, double y)
{
	char	*char_1;
	char	*char_2;

	char_1 = &cub->map.map[(int)((cub->player.y + y) / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	char_2 = &cub->map.map[(int)((cub->player.y) / MMAP_SZ)] \
		[(int)((cub->player.x + x) / MMAP_SZ)];
	auto char *old_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	cub_draw_player(cub, true);
	if (*char_1 != '1' && *char_1 != '-')
		cub->player.y += y;
	if (*char_2 != '1' && *char_2 != '-')
		cub->player.x += x;
	auto char *new_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	if (*old_c != *new_c)
	{
		*new_c = *old_c;
		*old_c = '0';
		cub_mmap_check(cub, true, false);
	}
	else
		cub_mmap_check(cub, false, false);
	cub_draw_player(cub, false);
}

void	cub_check_keys(t_cub *cub)
{
	if (cub->keys.right)
		cub_update_angle(cub, 1);
	else if (cub->keys.left)
		cub_update_angle(cub, -1);
	if (cub->keys.w)
		cub_move_player(cub, cos(cub->player.angle * M_PI / 180.0) * STEP, \
			sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.s)
		cub_move_player(cub, -cos(cub->player.angle * M_PI / 180.0) * STEP, \
			-sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.a)
		cub_move_player(cub, -cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, -sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
	else if (cub->keys.d)
		cub_move_player(cub, cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
}
