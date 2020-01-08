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

SRC		= 	main.c mx_ls.c mx_create_files_arr.c mx_create_flags_str.c \
			mx_files_in_dir.c mx_ls_get_acl_inf.c mx_ls_get_gid_name.c \
			mx_get_lstat.c mx_ls_get_print_name.c mx_ls_get_rwx_str.c \
			mx_get_terminal_width.c mx_ls_get_type.c mx_ls_get_uid_name.c \
			mx_ls_loop.c mx_ls_print_C.c mx_ls_print_l.c mx_ls_print.c \
			mx_print_lstat.c mx_read_dir.c mx_until_create_char_arr.c \
			mx_until_print_format_str.c

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
