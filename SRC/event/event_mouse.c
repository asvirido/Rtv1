/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:15:21 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/20 15:15:22 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		event_mouse(int keycode, int x, int y, t_rtv1 *rtv1)
{
	printf("keycode mouse = {%d} x %d y %d",keycode,x,y);
	return (1);
}
