# ************************************************************************** # 
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 07/10/2019 13:30:56 by vo-nguye          #+#    #+#             #
#   Updated: 07/10/2019 13:30:56 by vo-nguye         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = gnl.a

SRC = get_next_line.c get_next_line_utils.c


OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

OBJ : $(subst .o,.c,$(SRC))
	gcc -c  -D BUFFER_SIZE=32 $(CFLAGS) $(SRC)



$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re