#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_c;
	int			output_fd;
	char		*input_dir = "fanart/3b1b/input/sharp_2.txt";
	char		*output_dir = "fanart/3b1b/input/sharp.txt";
	float		*ker2;

	ker2 = edge_kernel(1, 10, 1, 0);
	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_chungaloider, false);
	scale_multiplication_fdf(&table_a, 3, HEIGHT);
	table_c = convolve_fdf(&table_a, ker2, 10);
	// scale_relu_fdf(&table_c, 0, 20, 0);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_chungaloider(output_fd, &table_c, HEIGHT);
	close(output_fd);

	free(ker2);
	free_table_fdf(&table_a);
	free_table_fdf(&table_c);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/3b1b/sharp.out
*/
