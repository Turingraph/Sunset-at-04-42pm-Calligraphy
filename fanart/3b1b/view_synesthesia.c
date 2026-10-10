#include "../../include/sunset442pm.h"

unsigned char red =   (15 + 50) / 2;
unsigned char green = (20 + 50) / 2;
unsigned char blue =  (45 + 50) / 2;

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
t_gradient	init_i()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 0;
	dst.input_end = 37;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_j()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 38;
	dst.input_end = 84;
	dst.rgba_start.r = 255 - 255;
	dst.rgba_start.g = 255 - 123;
	dst.rgba_start.b = 255 - 31;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255 - 229;
	dst.rgba_end.g = 255 - 11;
	dst.rgba_end.b = 255 - 112;
	dst.rgba_end.a = 255;
	return (dst);
}

t_gradient	init_k()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 85;
	dst.input_end = 160;
	dst.rgba_start.r = 255 - 114;
	dst.rgba_start.g = 255 -  40;
	dst.rgba_start.b = 255 - 255;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255 - 114;
	dst.rgba_end.g = 255 -  40;
	dst.rgba_end.b = 255 - 255;
	dst.rgba_end.a = 255;
	return (dst);
}

t_gradient	init_equal()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 160;
	dst.input_end = 230;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_minus()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 230;
	dst.input_end = 295;
	dst.rgba_start.r = 255 - 255;
	dst.rgba_start.g = 255 - 123;
	dst.rgba_start.b = 255 - 31;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255 - 229;
	dst.rgba_end.g = 255 - 11;
	dst.rgba_end.b = 255 - 112;
	dst.rgba_end.a = 255;
	return (dst);
}

t_gradient	init_one()
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 295;
	dst.input_end = 500;
	dst.rgba_start.r = 255 - 114;
	dst.rgba_start.g = 255 -  40;
	dst.rgba_start.b = 255 - 255;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255 - 114;
	dst.rgba_end.g = 255 -  40;
	dst.rgba_end.b = 255 - 255;
	dst.rgba_end.a = 255;
	return (dst);
}

t_gradient	init_3b1b()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r =  42;
	dst.rgba_start.g =  88;
	dst.rgba_start.b = 115;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 238;
	dst.rgba_end.g = 205;
	dst.rgba_end.b = 154;
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
	color_cells_gradient(&table, init_i(), true);
	color_cells_gradient(&table, init_j(), true);
	color_cells_gradient(&table, init_k(), true);
	color_cells_gradient(&table, init_equal(), true);
	color_cells_gradient(&table, init_minus(), true);
	color_cells_gradient(&table, init_one(), true);
	color_cells_gradient(&table, init_white_noise(), true);
	color_cells_gradient(&table, init_3b1b(), false);
	color_cells_gradient(&table, init_white_noise(), true);
	scale_multiplication_fdf(&table, 1.0 / 13.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(red, green, blue, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
./out/fanart/3b1b/view_synesthesia.out fanart/3b1b/input/sharp_5.txt
*/