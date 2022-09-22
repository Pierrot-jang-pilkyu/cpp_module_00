/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:04 by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 21:47:44 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map map)
{
	while (map.map)
	{
		ft_putstr_fd((char *)map.map->content, 1);
		map.map = map.map->next;
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_player	player;
	t_vars		vars;

	if (argc == 2)
	{
		inits(NULL, &player, &map, &vars);
		map.filename = argv[1];
		get_map(&map);
		// print_map(map);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 500, 500, "my");
		ft_mlx_img(&map, &player, &vars);
		mlx_loop(vars.mlx);
	}
	else
		put_error("Only One argument is required.");
	return (0);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;	
	int		j;	
	int		k;	


	// 그래픽 시스템에 커넥션을 만들고 void *를 리턴한다. 이 void *는 현재 MLX 인스턴스의 위치 좌표를 가진다(holds).
	mlx = mlx_init();
	// 화면을 띄우는 함수이다.
	mlx_win = mlx_new_window(mlx, 600, 400, "hello 42 seoul");
	// 이미지 생성
	img.img = mlx_new_image(mlx, 600, 400);
		이미지 주소는 있지만 아직 pixel이 없다.
	**	우리가 이를 위한 작업을 시작하기 전에 bytes가 정렬되어 있지 않음을 이해해야 한다.
	**	즉, line_length가 실제 창(윈도우) 너비와 다를 수 있다는 것이다.
	**	그래서 우리는 언제나 mlx_get_data_addr를 통해 set된 line_length를
	**	가지고 메모리 주소 출발점(offset)을 계산해야 한다.
	**	출발점은 다음 공식으로 구할 수 있다.
	**	int offset = (y * line_length + x * (bits_per_pixel / 8));*/ /*
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_loop 함수를 불러야 화면을 렌더링 시킬 수 있다.
	// 0x00 00 00 00
	//   t  r  g  b
	for (i = 250, k = 99; i < 300; i++, k -= 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	for (i = 300, k = 0; i < 350; i++, k += 2)
	{
		for (j = 150 + k; j < 250; j++)
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/