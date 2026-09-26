#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	int			output_fd;
	char		*input_dir = "fanart/suisei/input/scale_dim_edit.txt";
	char		*output_dir = "fanart/suisei/input/gauss.txt";
	t_matrix	ker;
	size_t		ker_dim;

	ker_dim = 5;
	ker.arr = gaussian_kernel(ker_dim / 2, 1, 1.0);
	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	table_b = convolve_fdf(&table_a, ker.arr, ker_dim);
	// scale_multiplication_fdf(&table_b, -1.0, HEIGHT);
	// scale_positive_fdf(&table_b);

	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_cheche01(output_fd, &table_b, HEIGHT);
	close(output_fd);

	free(ker.arr);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/suisei/convolve.out
*/
