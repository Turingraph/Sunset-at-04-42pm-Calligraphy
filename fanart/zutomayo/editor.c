#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_table_fdf	table_c;
	size_t		half_dim;
	int			output_fd;
	char		*input_dir = "fanart/zutomayo/input/figlet.txt";
	char		*output_dir = "fanart/zutomayo/input/convolve.txt";

	half_dim = 5;
	output_fd = open_dir_file(output_dir, NULL, APPEND);
	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf(&table_a, 3, 3);
	table_c = convolve_fdf(&table_b, NULL, half_dim);
	write_table_ascii_cheche01(output_fd, &table_c, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_table_fdf(&table_c);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/zutomayo/editor.out
*/