#include "../../include/sunset442pm.h"

unsigned char red =   255;
unsigned char green = 200;
unsigned char blue =  12 ;

// time : O(1)
// space: O(1)
t_gradient	init_white_noise(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r =  red;
	dst.rgba_start.g =green;
	dst.rgba_start.b = blue;
	dst.rgba_start.a =  255;
	dst.rgba_end.r =    red;
	dst.rgba_end.g =  green;
	dst.rgba_end.b =   blue;
	dst.rgba_end.a =    255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_popart(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_COL;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r = 187;
	dst.rgba_start.g = 113;
	dst.rgba_start.b = 121;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 240;
	dst.rgba_end.g = 139;
	dst.rgba_end.b =  77;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_feeling_blue(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 120;
	dst.rgba_start.r =  20;
	dst.rgba_start.g =  71;
	dst.rgba_start.b = 109;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 186;
	dst.rgba_end.g = 110;
	dst.rgba_end.b = 118;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_fdf_render	style;
	// t_gradient		text_color;

	// text_color = init_popart();
	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	// text_color.input_end = table.col;
	style.thickness = 2;
	style.shape_2d = E_RECTANGLE;
	color_cells_gradient(&table, init_feeling_blue(), true);
	scale_multiplication_fdf(&table, 1.0 / 20.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table, NULL, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(red, green, blue, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./out/fanart/yorushika/view_the_sun.out
*/
