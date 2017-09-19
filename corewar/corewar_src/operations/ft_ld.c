#include"../../includes/vm.h"

int		ft_ld(t_op *op, t_champ *champ)
{
	int		param_1;

	param_1 = 0;
	if (is_direct(op.opcode, 0) == 1)
		param_1 = champ.pc.param_types[0];
	else if (is_indirect(op.opcode, 0) == 1)
		param_1 = champ.pc.param_types[0];
	if (valid_reg(op.param_types[1]) == 1)
		champ->pc->value[1] = param_1 % IDX_MOD;
	champ->carry = (param_1) ? 0 : 1;
	return (0);
}
