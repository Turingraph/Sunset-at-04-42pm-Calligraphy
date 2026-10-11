#include "../../include/sunset442pm.h"

unsigned char red =   5;
unsigned char green = 5;
unsigned char blue =  10;

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_ROW;
	dst.input_start = 0;
	dst.input_end = 33;
	dst.rgba_start.r = (255 + 255) / 2;
	dst.rgba_start.g = (255 + 123) / 2;
	dst.rgba_start.b = (255 + 31 ) / 2;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = (255 + 229) / 2;
	dst.rgba_end.g = (255 + 11 ) / 2;
	dst.rgba_end.b = (255 + 112) / 2;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_studyme1()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 60;
	dst.rgba_start.r = (15 + 50) / 2;
	dst.rgba_start.g = (20 + 50) / 2;
	dst.rgba_start.b = (45 + 50) / 2;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 66;
	dst.rgba_end.g = 54;
	dst.rgba_end.b = 118;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_studyme()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 60;
	dst.rgba_start.r = 66;
	dst.rgba_start.g = 54;
	dst.rgba_start.b = 118;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 229;
	dst.rgba_end.g = 11;
	dst.rgba_end.b = 112;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_fdf_render	style;
	t_gradient		background;
	t_gradient		text_color;

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
	background = init_white_noise();
	background.input_end = table.row;
	color_cells_gradient(&table, background, true);
	text_color = init_ztmy_studyme1();
	text_color.input_end = get_minmax_from_table_fdf(&table, true, HEIGHT) / 2;
	color_cells_gradient(&table, text_color, true);
	text_color = init_ztmy_studyme();
	text_color.input_start = get_minmax_from_table_fdf(&table, true, HEIGHT) / 2;
	text_color.input_end = get_minmax_from_table_fdf(&table, true, HEIGHT);
	color_cells_gradient(&table, text_color, true);
	scale_multiplication_fdf(&table, 1.0 / 9.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(red, green, blue, 255));
	// view_fdf(&output, style, f_rgba_to_int32(14, 9, 15, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --tool=callgrind ./out/fanart/zutomayo/view_orange.out fanart/zutomayo/input/convolve.txt
valgrind --leak-check=full --show-leak-kinds=all 
./out/fanart/zutomayo/view_orange.out fanart/zutomayo/input/convolve.txt
*/