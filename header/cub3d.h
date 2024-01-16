#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map_name;
}			t_data;

int		main(int argc, char **argv);


#endif