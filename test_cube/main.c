#include "../includes/fdf.h"

int	main(void)
{
	t_mlx	info;
	t_img	img;

	info.tab = tab;
	__init_window(&info, &img, tab);
	
	mlx_hook(info.win_ptr, KeyPress, KeyPressMask, __key_press, &info);
	mlx_hook(info.win_ptr, ButtonPress, ButtonPressMask, __zoom, &info);
	mlx_hook(info.win_ptr, DestroyNotify, LeaveWindowMask, __close, &info);
	
	mlx_loop_hook(info.mlx_ptr, __write_img, &info);
	mlx_loop(info.mlx_ptr);
	
	mlx_destroy_window(info.mlx_ptr, info.win_ptr);
	mlx_destroy_image(info.mlx_ptr, info.img_ptr);
	mlx_destroy_display(info.mlx_ptr);		
	if (info.mlx_ptr)
		free(info.mlx_ptr);
	return (0);
}

int	__close(t_mlx *info)
{
	mlx_loop_end(info->mlx_ptr);
	return (0);
}

int	__zoom(int button, int x, int y, t_mlx *info)
{
	//printf("scale = %f, z_scale = %f\n", info->scale, info->z_scale);
	if (button == 4)
	{
		info->scale +=1;
		info->z_scale = (info->scale/(info->tab->z_max - info->tab->z_min)) * 4;
		info->redo = 0;
	}
	if (button == 5 && info->scale > 1)
	{
		info->scale -=1;
		info->z_scale = (info->scale/(info->tab->z_max - info->tab->z_min)) * 4;
		info->redo = 0;
	}
	return (0);
}

int	__key_press(int keycode, t_mlx *info)
{
	if (keycode == XK_Escape)
	{
		__close(info);
		return(0);
	}
	else if (keycode == XK_Up)
		info->shift_y -= 30;
	else if (keycode == XK_Down)
		info->shift_y += 30;
	else if (keycode == XK_Right)
		info->shift_x += 30;
	else if (keycode == XK_Left)
		info->shift_x -= 30;
	else if (keycode == XK_w)
		info->angle_y += 0.05;
	else if (keycode == XK_s)
		info->angle_y -= 0.05;
	else if (keycode == XK_d)
		info->angle_z += 0.05;
	else if (keycode == XK_a)
		info->angle_z -= 0.05;
	else
	{
		printf("keycode = %x\n", keycode);
		return (0);
	}
	info->redo = 0;
	return (0);
}

int	__write_img(t_mlx *info)
{
	int		y;
	int		x;
	t_point	a;
	t_point	b;
	void	*img_ptr;

	y = 0;
	if (info->redo == 1)
		return (0);
	img_ptr = info->img_ptr;
	__init_image(info);
	a.color = 0x00066FF;
	while (y < info->tab->y_max)
	{
		x = 0;
		a.z = info->tab->coordonnees[y][x];
		__calculate_xy(&a, x, y, info);
		//a.color = __color(a.z, info->tab);
		if (a.x > info->win_x || a.y > info->win_y)
		{
			y = info->tab->y_max;
			x = info->tab->x_max;
		}
		while (x < info->tab->x_max)// && x < info->win_x)
		{
			
			a.z = info->tab->coordonnees[y][x];
			//a.color = __color(a.z, info->tab);
			//printf("x = %d, y = %d\n        COLOR = %x\n", x, y, a.color);
			//printf("color = %x\n", a.color);
			__calculate_xy(&a, x, y, info);
			//printf("A x = %d, y = %d, z = %d\n", x, y , info->tab->coordonnees[y][x]);
			if (a.x > info->win_x || a.y > info->win_y)
				x = info->tab->x_max;
			else
			{
				if (y < info->tab->y_max - 1)
				{
					b.z = info->tab->coordonnees[y + 1][x];
					//printf("By x = %d, y = %d, z = %d\n", x, y+1 , info->tab->coordonnees[y+1][x]);
					//b.color = __color(b.z, info->tab);
					__calculate_xy(&a, x, y, info);
					__calculate_xy(&b, x, y + 1, info);
					__draw_a_line(&a, &b, info);
				}
				if (x < info->tab->x_max - 1)
				{
					a.z = info->tab->coordonnees[y][x];
					__calculate_xy(&a, x, y, info);
					b.z = info->tab->coordonnees[y][x + 1];
					//printf("Bx x = %d, y = %d, z = %d x_max = %d\n", x+1, y , info->tab->coordonnees[y][x+1], info->tab->x_max);
					//b.color = __color(b.z, info->tab);
					__calculate_xy(&b, x + 1, y, info);
					__draw_a_line(&a, &b, info);
				}
				
			}
			x++;
		}
		y++;
	}
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, img_ptr);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	info->redo = 1;
	return (0);
}

int	__color(int z, t_tab *tab)
{
	float z_diff;
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	z_diff = tab->z_max - tab->z_min;
	z_diff = fabs((z_diff - (z_diff - z)) / z_diff);
	red = 255 * z_diff;
	green = 102 - 102 * z_diff;
	blue = 255 - z_diff * 153;
	//printf("red = %d, green = %d, blue = %d z_diff = %f, z = %d\n", red, green, blue, z_diff, z);
	return ( red << 16 | green << 8 | blue);
}

void	__calculate_xy(t_point *point, int x, int y, t_mlx *info)
{
	point->x = x * info->scale;
	point->y = y * info->scale;
	point->z *= info->z_scale;
	__rotate_x(point, info);
	__rotate_y(point, info);
	__rotate_z(point, info);
	printf("x = %d, y = %d, z = %d\n", point->x, point->y, point->z);
	point->x = (((x) - (y)) * cos(info->angle)) \
	+ info->shift_x;
	point->y = ((((x) + (y)) \
	* sin(info->angle)) - point->z) + info->shift_y;
}

void	__rotate_x(t_point *point, t_mlx *info)
{
	int y;
	int z;

	y = point->y;
	z = point->z;
	point->y = y * cos(info->angle_x) - z * cos(info->angle_x);
	point->z = z * cos(info->angle_x) + y * cos(info->angle_x);
}

void	__rotate_y(t_point *point, t_mlx *info)
{
	int x;
	int z;

	x = point->x;
	z = point->z;
	point->x = x * cos(info->angle_y) - z * cos(info->angle_y);
	point->z = z * cos(info->angle_y) + x * cos(info->angle_y);
}

void	__rotate_z(t_point *point, t_mlx *info)
{
	int x;
	int y;

	x = point->x;
	y = point->y;
	point->x = x * cos(info->angle_z) - y * cos(info->angle_z);
	point->y = y * cos(info->angle_z) + x * cos(info->angle_z);
}

int	__init_window(t_mlx *info, t_img *img, t_tab *tab)
{
	info->win_x = 2000;
	info->win_y = 1000;
	info->scale = tab->z_max - tab->z_min;
	info->z_scale = 4;
	/*while (info->win_x - tab->x_max * info->scale > 0 && info->win_y - tab->y_max * info->scale > 0)
	{
		info->scale += tab->z_max - tab->z_min;
		info->z_scale += 4;
	}*/
	info->angle = 0.523599;
	info->angle_x = 0.0;
	info->angle_y = 0.0;
	info->angle_z = 0.0;
	info->redo = 0;
	info->shift_x = info->win_x / 3;
	info->shift_y = info->win_y / 3;
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 2000, 1000, "FdF");
	info->img_ptr = mlx_new_image(info->mlx_ptr, 2000, 1000);
	img->img_addr = mlx_get_data_addr(info->img_ptr, &img->bpp, \
	&img->size_line, &img->endian);
	info->img = img;
	return (0);
}

void	__init_image(t_mlx *info)
{
	info->img_ptr = mlx_new_image(info->mlx_ptr, 2000, 1000);
	info->img->img_addr = mlx_get_data_addr(info->img_ptr, &info->img->bpp, \
	&info->img->size_line, &info->img->endian);
}

void	__my_mlx_pixel_put(t_mlx *info, int x, int y, int color)
{
	char	*dst;
	
	if (x < info->win_x && y < info->win_y && x > -1 && y > -1)
	{
		dst = info->img->img_addr + (y * info->img->size_line + x * (info->img->bpp / 8));
		*(unsigned int *) dst = color;
	}
	
}

void	__swap_ab(t_point *a, t_point *b)
{
	int	temp;

	//printf("SWAP\n");
	temp = a->x;
	a->x = b->x;
	b->x = temp;
	temp = a->y;
	a->y = b->y;
	b->y = temp;
	temp = a->z;
	a->z = b->z;
	b->z = temp;
	temp = b->color;
	b->color = a->color;
	a->color = temp;
}

int	__abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}