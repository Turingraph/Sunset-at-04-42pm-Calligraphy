#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_table_fdf	table_c;
	size_t		half_dim;
	int			output_fd;
	char		*dst_dir = "unit_test/editor/convolve/input_ascii/";
	char		*src_dir = "input_examples/ascii/";
	char		*input = "fanart/zutomayo/input/figlet.txt";
	char		*output = "fanart/zutomayo/input/convolve.txt";

	half_dim = 5;
	output_fd = open_dir_file(output, NULL, APPEND);
	table_a = open_table_fdf_file(input, src_dir,
			parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf(&table_a, 3, 3);
	table_c = convolve_fdf(&table_b, NULL, half_dim);
	write_table_ascii_cheche01(output_fd, &table_c, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_table_fdf(&table_c);
	return (0);
}

