#include "../header/cub3d.h"

static int	check_argc(int argc)
{
	if (argc < 2)
		return (ft_printf("Error\nNo map given to the program."),
			1);
	if (argc > 2)
		return (ft_printf("Error\nToo many arguments."), 1);
	return (0);
}

static int	parsing_and_error(t_data *param, char *name)
{
	// init_param(param);
	// param->map_name = ft_strdup(name);
	// if (!param->map_name)
	// 	return (0);
	// if (map_parsing(param, -1) == 1)
	// 	return (free(param->map_name), free_all_param(param), 0);
	// if (check_error(param) == 0)
	// 	return (free(param->map_name), free_all_param(param), 0);
	// return (1);
}

int	main(int argc, char **argv)
{
	t_data param;

	if (check_argc(argc))
		return (0);
	if (parsing_and_error(&param, argv[1] == 0))
		return (0);
	return (0);
}