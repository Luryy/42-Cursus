	void	*init;

	init = mlx_init();
	mlx_new_window(init, 1000, 1000, "FDF");
	mlx_loop(init);
	return (1);