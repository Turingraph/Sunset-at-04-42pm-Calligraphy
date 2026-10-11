#include "../../include/sunset442pm.h"

// time : O(1)
// space: O(1)
t_gradient	init_all()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 500;
	dst.rgba_start.r = 251;
	dst.rgba_start.g = 174;
	dst.rgba_start.b = 67;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 221;
	dst.rgba_end.g = 209;
	dst.rgba_end.b = 167;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_floor()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 10;
	dst.rgba_start.r = 126;
	dst.rgba_start.g = 46;
	dst.rgba_start.b = 3;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 176;
	dst.rgba_end.g = 110;
	dst.rgba_end.b = 3;
	dst.rgba_end.a = 255;
	return (dst);
}

unsigned char red =   173 / 2;
unsigned char green = 124 / 2;
unsigned char blue =   68 / 2;

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

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_fdf_render	style;
	t_gradient		wood;
	size_t			i;

	if (len < 2)
		return (0);
	wood = init_floor();
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	color_cells_gradient(&table, init_all(), true);
	style.thickness = 3;
	style.shape_2d = E_LINE;
	i = 0;
	while (i < 24)
	{
		wood.input_start += 15;
		wood.input_end += 15;
		color_cells_gradient(&table, wood, true);
		i += 1;
	}
	color_cells_gradient(&table, init_white_noise(), true);
	scale_multiplication_fdf(&table, 1.0 / 10.0, HEIGHT);
	output = init_fdf(&table, projection_isometric, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(0, 0, 0, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./out/improvise/wood/view_wood.out fanart/zutomayo/input/convolve.txt

*/