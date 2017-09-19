static void		check_player_numbers(t_champ *champs, char *nums)
{
	int		i;
	char	possible;
	
	possible = '1';
	i = 0;
	while (i < num_players)
	{
		if [nums[i] == 0]
		{
			while (ft_strchr(nums, possible) != NULL)
				possible++;
			nums[i] == possible;
			champs[i].player_num = possible - '0';
		}
		i++;
	}
	i = 0;
}

static int		new_champ(char *file_name, t_champ *champ, play_num)
{
	if (play_num <= MAX_PLAYERS && play_num >= 0)
	{
		champ->filename = file_name;	//ptr aliasing could be prob
		if (champ->fd = open(filename, O_RDONLY) < 0)
		{
			ft_putstr_fd("could not open: ", 2);
			ft_putendl_fd(file_name, 2);	
			return (-1);
		}
		champ->player_num = play_num;
		ft_bzero(champ->name, PROG_NAME_LENGTH + 1);
		ft_bzero(champ->comment, COMMENT_LENGTH + 1);
		ft_bzero(champ->code, MAX_CHAMP_SIZE + 1);
		champ->size = 0;
		champ->carry = 0;
		champ->load_address = 0;
		return (1);
	}
	ft_putendl_fd("player number specified exceeds MAX_PLAYERS", 2);
	return (-1);
}

/**
** ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...
**/

int		init_env_loop(int argc, char **argv, t_env *env, int i)
{
	while (i < argc)
	{
		if (ft_strcmp(arg[i], "-dump") == 0)
		{	
			if (env->dump != 0 || !argv[i + 1] || ft_isnumber(argv[i + 1]) < 0)    //check return of ft_isnumber
				return (-1);
			env->dump = ft_atoi(argv[i + 1]);
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
		{
			if ((i + 2) < argc && ft_isnumber(argv[i + 1]) && ft_strstr(argv[i + 2], ".cor") != NULL)
			{
				if (new_champ(arg[i + 2], &(env->champs[env->num_players]),
					ft_atoi(arg[i + 1])) < 0)
					return (-1);
				env->player_nums[num_players] = ft_atoi(arg[i + 1]) + '0';
				env->num_players++;
			}
			else
				return (-1);
			i += 2;
		}
		else if (ft_strstr(argv[i], ".cor") != NULL)
		{
			if (new_champ(argv[i], env->champs, 0) < 0)
				return (-1);
			env->num_players++;
		}
		i++;
	}
	return (1);
}

int		init_env(int argc, char **argv, t_env *env)
{
	int i;

	i = 1;
	env->dump = 0;
	env->num_players = 0;
	ft_bzero(env->player_nums, MAX_PLAYERS);
	if (init_env_loop(argc, argv, env, i) < 0)
		return (-1);
	check_player_numbers(env->champs, env->player_nums)
	init_arena(env);
	return (1);
}