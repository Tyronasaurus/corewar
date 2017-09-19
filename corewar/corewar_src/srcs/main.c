
"./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."



int		main(int argc, char **argv)
{
	t_env	env;

	if (init_env(argc, argv, &env) < 0)
	{
		ft_putendl_fd(PARAM_ERROR, 2);
		return (-1);
	}
	if (read_champ_data(&env.champs, env.num_players) < 0)
	{
		ft_putendl_fd("Read .cor error", 2);
		return (-1);
	}
	return (0);	
}