/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:14:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/16 19:14:08 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static int   print_vector(t_vector *a)
{
   printf("a.x = [%f]\n",a->x);
   printf("a.y = [%f]\n",a->y);
   printf("a.z = [%f]\n",a->z);
   return (1);
}

void	ft_migr(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 126)
	{
      //rtv1->rt_obj[5].cylinder->position->z += 10;
		//rtv1->rt_obj[1].sphere->position->z += 10;
	rtv1->light[0].position->y += 10;
	}
	else if (keycode == 125)
	{
		rtv1->light[0].position->y -= 10;
     // rtv1->rt_obj[5].cylinder->position->z -= 10;
		//rtv1->rt_obj[1].sphere->position->z -= 10;
	}
   else if (keycode == 123)
   {
      	rtv1->rt_obj[1].sphere->position->x -= 10;
   }
   else if (keycode == 124)
   {
         rtv1->rt_obj[1].sphere->position->x += 10;
   }
	print_vector(rtv1->light[0].position);
	ray_tracing(rtv1);
}

int		plus(int keycode, t_rtv1 *rt)
{
	printf("keycode %d\n",keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		ft_migr(rt, keycode);
	return (1);
}

void 		mlx_use(t_rtv1 *rtv1)
{
	mlx_key_hook(WIN_MY, event_key, rtv1);
	mlx_hook(WIN_MY, 2, 5, plus, rtv1);
	mlx_mouse_hook(WIN_MY, event_mouse, rtv1);
	mlx_hook(WIN_MY, 17, 0, destroy, 0);
	mlx_loop(MLX_MY);
}
int		main(void)
{
	t_rtv1		*rtv1;

	rtv1 = create_rtv1();
	ray_tracing(rtv1);
	mlx_use(rtv1);
	return (0);
}
