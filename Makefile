################################################################################
#                                     CONFIG                                   #
################################################################################

NAME     := pipex
CC       := cc
FLAGS    := -Wall -Wextra -Werror -g -fsanitize=address
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      libft/ft_lstdelone.c \
						  libft/ft_isalpha.c \
						  libft/ft_lstlast.c \
						  libft/ft_memcmp.c \
						  libft/ft_itoa.c \
						  libft/ft_memset.c \
						  libft/ft_strnstr.c \
						  libft/ft_putchar_fd.c \
						  libft/ft_lstiter.c \
						  libft/ft_isalnum.c \
						  libft/ft_strtrim.c \
						  libft/ft_lstclear.c \
						  libft/ft_strmapi.c \
						  libft/ft_lstsize.c \
						  libft/ft_isdigit.c \
						  libft/ft_memmove.c \
						  libft/ft_putnbr_fd.c \
						  libft/ft_calloc.c \
						  libft/ft_putstr_fd.c \
						  libft/ft_toupper.c \
						  libft/ft_isprint.c \
						  libft/ft_tolower.c \
						  libft/ft_isascii.c \
						  libft/ft_atoi.c \
						  libft/ft_substr.c \
						  libft/ft_strrchr.c \
						  libft/ft_strdup.c \
						  libft/ft_strlcpy.c \
						  libft/ft_striteri.c \
						  libft/ft_lstadd_back.c \
						  libft/ft_split.c \
						  libft/ft_strchr.c \
						  libft/ft_memchr.c \
						  libft/ft_putendl_fd.c \
						  libft/ft_lstnew.c \
						  libft/ft_strlcat.c \
						  libft/ft_strncmp.c \
						  libft/ft_lstmap.c \
						  libft/ft_lstadd_front.c \
						  libft/ft_strlen.c \
						  libft/ft_strjoin.c \
						  libft/ft_bzero.c \
						  libft/ft_memcpy.c \
						  ft_printf/ft_printf.c \
						  ft_printf/ft_putchar.c \
						  ft_printf/ft_putlu.c \
						  ft_printf/ft_putnbr_base.c \
						  ft_printf/ft_putptr.c \
						  ft_printf/ft_putstr.c \
						  ft_printf/ft_putuint.c \
						  src/pipex.c \
						  src/utils.c \
						  src/clean.c \
						  
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

perfect:	all
			@ ${RM} *.o */*.o */*/*.o
			clear
			@printf "$(GREEN)  >>-----------DONE----------<<\r"
			@sleep 0.1
			@printf "$(GREEN)  >>>>---------DONE--------<<<<\r"
			@sleep 0.1
			@printf "$(GREEN)  >>>>>>-------DONE------<<<<<<\r"
			@sleep 0.1
			@printf "$(GREEN)  >>>>>>>>-----DONE-----<<<<<<<\r"
			@sleep 0.1
			@printf "$(GREEN)  >>>>>>>>>>---DONE---<<<<<<<<<\r"
			@sleep 0.1
			@printf "$(GREEN)  >>>>>>>>>>>>-DONE-<<<<<<<<<<<\r"
			@sleep 0.3
			@printf "                                       \r"
			@printf "\033[2;32m               DONE!            \r"
			@sleep 0.1
			@printf "\033[1;;32m               DONE! \n"
			@sleep 0.1
			clear
			@echo "$(GREEN)$(NAME) created[0m ✔️"

.PHONY:		all clean fclean re perfect