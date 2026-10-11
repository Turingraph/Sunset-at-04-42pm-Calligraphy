#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf		table_base;
	t_table_fdf		table;
	char		*output_dir = "improvise/non_euclidean/input/hyperbolic.txt";
	int			output_fd;
	size_t		ker_dim;
	t_table_fdf	table_c;
	t_matrix	ker;

	ker_dim = 3;
	ker.arr = gaussian_kernel(ker_dim / 2, 1., 1.);
	table_base = init_table_fdf(300, 300, false);
	set_cells_color(&table_base, 3, HEIGHT, is_andmod_x3);
	table = init_table_fdf(300, 300, true);
	paint_space(&table, HEIGHT, cell_metric_amgm_inequality);
	paint_space(&table, HEIGHT, cell_metric_max_xyz);
	table_fdf_hadamard(&table, &table_base, HEIGHT);
	table_c = convolve_fdf(&table, ker.arr, ker_dim);
	scale_multiplication_fdf(&table_c, 1.0 / 2.0, HEIGHT);
	// sin_table(&table);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_chungaloider(output_fd, &table_c, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_c);
	free(ker.arr);
	free_table_fdf(&table_base);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/improvise/non_euclidean/print_hyper.out
*/
