#include "../../include/sunset442pm.h"

int	main(void)
{
	char		*input_dir = "fanart/zutomayo/input/convolve.txt";
	char		*output_dir = "fanart/zutomayo/input/convolve_3.txt";
	t_table_fdf	table;
	int			output_fd;

	table = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	scale_multiplication_fdf(&table, 13, HEIGHT);
	write_table_ascii_cheche01(output_fd, &table, HEIGHT);
	close(output_fd);
	free_table_fdf(&table);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/zutomayo/scale_3.out
*/

