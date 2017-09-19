static void		clean_arena(t_reg *arena)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_bzero (arean->value, 3);
		arena->champ_num = 0;
		i++;
	}
}

void			init_arena(t_env *env)
{
	clean_arean(env->arena);
}