#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf		table_base;
	t_table_fdf		table;
	char		*output_dir = "improvise/wood/input/wood.txt";
	int			output_fd;
	float		maxx;

	table_base = init_table_fdf(300, 300, false);
	set_cells_color(&table_base, 3, HEIGHT, is_oddlength_x2shadow);
	table = init_table_fdf(300, 300, true);
	// paint_space(&table, HEIGHT, cell_metric_root_xy);
	paint_space(&table, HEIGHT, cell_metric_amgm_inequality);
	paint_space(&table, HEIGHT, cell_metric_pythagoras_3d);
	table_fdf_hadamard(&table, &table_base, HEIGHT);
	maxx = get_minmax_from_table_fdf(&table, true, HEIGHT) / 50;
	if (maxx > 0.2)
		maxx = 1 / maxx;
	scale_multiplication_fdf(&table, maxx, HEIGHT);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_chungaloider(output_fd, &table, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_base);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/improvise/wood/print.out
*/
