# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 14:46:37 by cpauwels          #+#    #+#              #
#    Updated: 2017/09/12 13:05:13 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_ASM = asm_src/asm
#BIN_COREWAR = corewar_src/corewar

all:
	@echo "-------------------Make Libft-----------------"
	make -C libft
	@echo "------------------Make ASM-------------------"
	make -C asm_src
	cp $(BIN_ASM) .
	#cp $(BIN_COREWAR)

norm:
	norminette asm_src/

clean:
	make clean -C libft
	make clean -C asm_src

fclean:
	make fclean -C libft
	make fclean -C asm_src
	rm asm
	#rm corewar
