/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:15:21 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:53:49 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		event_mouse(int keycode, int x, int y, t_rtv1 *rtv1)
{
	if (keycode == 5 || keycode == 4)
		zoom(keycode, x, y, rtv1);
	return (1);
}
