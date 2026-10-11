#include "../../include/sunset442pm.h"

int	main(void)
{
	t_table_fdf	table;
	int			output_fd;
	char		*input_dir = "fanart/suisei/input/sharp_edit.txt";
	char		*output_dir = "fanart/suisei/input/inverse_edit.txt";

	table = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	output_fd = open_dir_file(output_dir, NULL, E_WRITE);
	scale_multiplication_fdf(&table, -1.0, HEIGHT);
	scale_positive_fdf(&table);
	write_table_ascii_cheche01(output_fd, &table, HEIGHT);
	close(output_fd);
	free_table_fdf(&table);
	return (0);
}

/*
./out/fanart/suisei/inverse.out
*/