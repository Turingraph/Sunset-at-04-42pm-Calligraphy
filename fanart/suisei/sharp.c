#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_c;
	int			output_fd;
	char		*input_dir = "fanart/suisei/input/gauss.txt";
	char		*output_dir = "fanart/suisei/input/sharp.txt";
	float		*ker2;

	ker2 = edge_kernel(1, 10, 1, 0);
	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	table_c = convolve_fdf(&table_a, ker2, 10);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	write_table_ascii_cheche01(output_fd, &table_c, HEIGHT);
	close(output_fd);

	free(ker2);
	free_table_fdf(&table_a);
	free_table_fdf(&table_c);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./out/fanart/suisei/sharp.out
*/
