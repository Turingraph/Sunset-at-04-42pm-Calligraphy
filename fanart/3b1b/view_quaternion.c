#include "../../include/sunset442pm.h"

unsigned char red =   (15 + 5) / 2;
unsigned char green = (20 + 5) / 2;
unsigned char blue =  (45 + 5) / 2;

// (231, 200, 239)
unsigned char red2 =   231;
unsigned char green2 = 200;
unsigned char blue2 =  239;

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_ROW;
	dst.input_start = 0;
	dst.input_end = 63;
	dst.rgba_start.r = red;
	dst.rgba_start.g = green;
	dst.rgba_start.b = blue;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = red2;
	dst.rgba_end.g = green2;
	dst.rgba_end.b = blue2;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_white_noise2()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = red;
	dst.rgba_start.g = green;
	dst.rgba_start.b = blue;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = red;
	dst.rgba_end.g = green;
	dst.rgba_end.b = blue;
	dst.rgba_end.a = 255;
	return (dst);
}


// time : O(1)
// space: O(1)
t_gradient	init_backroom()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 70;
	dst.rgba_start.r =   8;
	dst.rgba_start.g =  28;
	dst.rgba_start.b =  35;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 247;
	dst.rgba_end.g = 193;
	dst.rgba_end.b = 103;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_3b1b()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 41;
	dst.input_end = 80;
	dst.rgba_start.r =   8;
	dst.rgba_start.g =  28;
	dst.rgba_start.b =  35;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 102;
	dst.rgba_end.g = 134;
	dst.rgba_end.b = 255;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_fdf_render	style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	style.thickness = 3;
	style.shape_2d = E_CIRCLE;
	color_cells_gradient(&table, init_white_noise(), true);
	color_cells_gradient(&table, init_backroom(), true);
	color_cells_gradient(&table, init_3b1b(), false);
	color_cells_gradient(&table, init_white_noise2(), true);
	// set_cells_color(&table, 255, RED, is_boundary_fdf);
	// set_cells_color(&table, 255, GREEN, is_boundary_fdf);
	// set_cells_color(&table, 255, BLUE, is_boundary_fdf);
	scale_multiplication_fdf(&table, 1.0 / 13.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(red, green, blue, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
./out/fanart/3b1b/view_quaternion.out fanart/3b1b/input/sharp_5.txt
*/