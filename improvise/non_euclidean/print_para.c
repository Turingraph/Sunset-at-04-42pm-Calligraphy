#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf		table_base;
	t_table_fdf		table;
	char		*output_dir = "improvise/non_euclidean/input/parabolic.txt";
	int			output_fd;

	table_base = init_table_fdf(300, 300, false);
	set_cells_color(&table_base, 3, HEIGHT, is_oddlength_x2shadow);
	table = init_table_fdf(300, 300, true);
	paint_space(&table, HEIGHT, cell_metric_max_xy);
	table_fdf_hadamard(&table, &table_base, HEIGHT);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_chungaloider(output_fd, &table, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_base);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/improvise/non_euclidean/print_para.out
*/
