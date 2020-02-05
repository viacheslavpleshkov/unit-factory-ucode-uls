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

SRC		= 	main.c mx_ls.c mx_ls_loop.c mx_files_in_dir.c \
			mx_ls_get_rwx_str.c mx_ls_create_struct_arr.c \
			mx_ls_get_hidden.c mx_read_dir.c mx_ls_get_uid_name.c \
			mx_create_param_arr.c mx_create_flags_str.c mx_ls_get_acl_inf.c \
			mx_ls_get_gid_name.c mx_get_lstat.c mx_ls_get_print_name.c \
			mx_get_terminal_width.c mx_ls_get_type.c mx_ls_print.c \
			mx_ls_print_big_c.c mx_ls_print_l.c mx_ls_print_big_t.c \
			mx_ls_sort.c mx_ls_sort_default.c mx_ls_sort_flag_r.c \
			mx_ls_sort_flag_big_s.c mx_ls_sort_flag_c.c mx_ls_sort_flag_t.c \
			mx_ls_sort_flag_u.c mx_until_get_size_arr.c mx_until_create_char_arr.c \
			mx_until_print_format_str.c mx_until_get_len_number.c \
			mx_untill_get_max_nlink.c mx_untill_get_max_size.c mx_ls_check_flag.c \
			mx_create_main.c mx_untill_del_tls.c mx_valid_flags.c mx_clear_flags.c \
			mx_insort_lstat.c mx_ls_print_1.c mx_ls_print_color.c mx_ls_print_link_name.c \
			mx_ls_get_color.c 

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "	

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
