#include "../../include/sunset442pm.h"

unsigned char red =   0;
unsigned char green = 0;
unsigned char blue =  0;

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
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
t_gradient	init_3b1b()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r = 15;
	dst.rgba_start.g = 59;
	dst.rgba_start.b = 72;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 135;
	dst.rgba_end.g = 194;
	dst.rgba_end.b = 208;
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
	style.shape_2d = E_LINE;
	color_cells_gradient(&table, init_3b1b(), true);
	color_cells_gradient(&table, init_white_noise(), true);
	scale_multiplication_fdf(&table, 1.0 / 13.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(red, green, blue, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
./out/fanart/3b1b/view_manim.out fanart/3b1b/input/sharp_5.txt
*/