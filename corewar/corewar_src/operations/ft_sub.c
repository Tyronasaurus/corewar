#include "../../includes/vm.h"

int		ft_sub(t_op *op, t_champ *champ)
{
	int		a;
	int		b;

	if (valid_reg(op.param_types[0]) == 1)
		a = champ->pc->value[0];
	if (valid_reg(op.param_types[1]) == 1)
		b = champ->pc->value[1];
	if (valid_reg(op.param_types[2]) == 1)
		champ->pc->value[2] = a - b;
	champ->carry = (a - b) ? 0 : 1;
	return (0);
}
