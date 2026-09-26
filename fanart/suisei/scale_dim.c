#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	int			output_fd;
	char		*input_dir = "fanart/suisei/input/figlet.txt";
	char		*output_dir_1 = "fanart/suisei/input/scale_dim.txt";

	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	scale_relu_fdf(&table_a, 1, 20, 5);
	scale_multiplication_fdf(&table_a, 10, HEIGHT);
	table_b = scale_dimension_fdf(&table_a, 8, 4);

	output_fd = open_dir_file(output_dir_1, NULL, E_WRITE);
	write_table_ascii_cheche01(output_fd, &table_b, HEIGHT);
	close(output_fd);

	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/suisei/scale_dim.out
*/
