/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 19:09:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_draw_mmap_c_4(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_3 - 2;
	while (++alt_y < MMAP_SZ_3)
	{
		auto int x = -1;
		while (++x < MMAP_SZ_3)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		y++;
	}
	cub_small_update_c(cub);
}

void	cub_draw_mmap_c_5(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_3 - 2;
	while (++alt_y < MMAP_SZ_3)
	{
		auto int alt_x = -1;
		auto int x = cub->map.width - MMAP_SZ_3 - 2;
		while (++alt_x < MMAP_SZ_3)
		{
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
			x++;
		}
		y++;
	}
	cub_small_update_c(cub);
}

void	cub_draw_mmap_c_6(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_3 - 2;
	while (++alt_y < MMAP_SZ_3)
	{
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MMAP_3 - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MMAP_3 + MMAP_SZ_3)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		y++;
	}
	cub_small_update_c(cub);
}
