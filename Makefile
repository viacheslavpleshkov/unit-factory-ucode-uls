NAME	=	uls

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		= 	main.c  mx_begin.c mx_create_files_arr.c mx_create_opt_str.c \
			mx_files_in_dir.c mx_get_acl_inf.c mx_get_gid_name.c mx_get_lstat.c \
			mx_get_print_name.c mx_get_rwx_str.c mx_get_terminal_width.c  \
			mx_get_type.c mx_get_uid_name.c mx_loop.c mx_print_ls.c mx_print_ls_C.c \
			mx_print_ls_l.c mx_print_lstat.c mx_read_dir.c 

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME)\t   \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME)\t   \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
