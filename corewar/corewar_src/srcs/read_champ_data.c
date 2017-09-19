static int		check_magic(t_champ *champ)
{
	char	magic[5];
	int		mag;

	ft_bzero(magic, 5);
	if (read(champ->fd, magic, sizeof(COREWAR_EXEC_MAGIC)) < 0)
		return (-1);
	magic[1] = 'x'
	mag = ft_atoi(magic);       // problem here. Determine the value held at magic and then write hex to decimal function
	if (mag == COREWAR_EXEC_MAGIC)
		return (0);
	return (-1);
}

static int		get_name_and_size(t_champ *champ)
{
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC)) < 0)  //possible that this lseek is not nesessary as the cursor depends on the order of calls to functions
		return (-1);
	if (read(champ->fd, champ->name, PROG_NAME_LENGTH) < 0)  //Will take some tinkering but after printing out the name
		return (-1);
}

static int		get_comment(t_champ *champ)
{
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH + sizeof(int)) < 0)
		return (-1);
	if (read(champ->fd, champ->comment, COMMENT_LENGTH) < 0)
		return (-1);
}


int		read_champ_data(t_champ *champs, int num_champs)
{
	int	i;

	i = 0;
	while (i < num_champs)
	{
		if (check_magic(champs + i) < 0 || get_name(champs + i) < 0 ||
			get_stated_size(champs + i) < 0 || get_comment(champs + i) < 0)
			return (-1);
		else if (close(champs[i].fd) < 0)
			return (-1);
		i++;
	}
}
