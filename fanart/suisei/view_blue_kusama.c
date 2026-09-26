#include "../../include/sunset442pm.h"


// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 221;
	dst.rgba_start.g = 212;
	dst.rgba_start.b = 35;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 221;
	dst.rgba_end.g = 212;
	dst.rgba_end.b = 35;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_suisei()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 9;
	dst.rgba_start.b = 145;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 12;
	dst.rgba_end.g = 186;
	dst.rgba_end.b = 231;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_caramel_pain()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 75;
	dst.input_end = 80;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 123;
	dst.rgba_start.b = 31;
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
	t_table_fdf		non_euclidean;
	t_fdf			output;
	t_render_style	style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	// scale_multiplication_fdf(&table, -1, HEIGHT);
	// scale_positive_fdf(&table);
	non_euclidean = init_table_fdf(table.row, table.col, true);
	paint_space(&non_euclidean, HEIGHT, cell_metric_pythagoras);
	style.background_color = f_rgba_to_int32(70, 155, 178, 255);
	style.line_thickness = 4;
	style.artist = E_KUSAMA;
	scale_multiplication_fdf(&table, -1.0, HEIGHT);
	scale_positive_fdf(&table);
	color_cells_gradient(&table, init_suisei(), true);
	color_cells_gradient(&table, init_caramel_pain(), true);
	color_cells_gradient(&table, init_white_noise(), true);
	scale_multiplication_fdf(&table, 1.0 / 25.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./out/fanart/suisei/view_blue_kusama.out fanart/suisei/input/sharp_edit.txt
*/
