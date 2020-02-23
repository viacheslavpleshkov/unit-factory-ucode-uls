APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = \
inc/ \
libmx/inc/

SRC_DIR = src

OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/,\
	creating/mx_ls_create_flags_str.c \
	creating/mx_ls_create_main.c \
	creating/mx_ls_create_param_arr.c \
	creating/mx_ls_create_struct_arr.c \
	creating/mx_ls_create_struct_print_l.c \
	inserts/mx_ls_insert_lstat.c \
	parsing/mx_ls_get_acl_inf.c \
	parsing/mx_ls_get_color.c \
	parsing/mx_ls_get_gid_name.c \
	parsing/mx_ls_get_hidden.c \
	parsing/mx_ls_get_ino_dev_fd.c \
	parsing/mx_ls_get_lstat.c \
	parsing/mx_ls_get_print_name.c \
	parsing/mx_ls_get_rwx_str.c \
	parsing/mx_ls_get_terminal_width.c \
	parsing/mx_ls_get_time_str.c \
	parsing/mx_ls_get_type.c \
	parsing/mx_ls_get_uid_name.c \
	parsing/mx_ls_get_xattr.c \
	parsing/mx_ls_read_dir.c \
	printing/mx_ls_print_big_c.c \
	printing/mx_ls_print_color.c \
	printing/mx_ls_print_l.c \
	printing/mx_ls_print_link_name.c \
	printing/mx_ls_print_m.c \
	printing/mx_ls_print_one.c \
	printing/mx_ls_print_rwx.c \
	printing/mx_ls_print.c \
	sortings/mx_ls_sort.c \
	sortings/mx_ls_sort_default.c \
	sortings/mx_ls_sort_flag_big_s.c \
	sortings/mx_ls_sort_flag_c.c \
	sortings/mx_ls_sort_flag_r.c \
	sortings/mx_ls_sort_flag_t.c \
	sortings/mx_ls_sort_flag_u.c \
	utils/mx_until_check_flag.c \
	utils/mx_until_create_char_arr.c \
	utils/mx_until_del_tls.c \
	utils/mx_until_files_in_dir.c \
	utils/mx_until_get_len_number.c \
	utils/mx_until_get_max_nlink.c \
	utils/mx_until_get_max_size.c \
	utils/mx_until_get_size_arr.c \
	utils/mx_until_major_minor.c \
	utils/mx_until_max_gid_str.c \
	utils/mx_until_max_uid_str.c \
	utils/mx_until_print_format_str.c \
	validations/mx_ls_check_character_files.c \
	validations/mx_ls_clear_flags.c \
	validations/mx_ls_error.c \
	validations/mx_ls_valid_flags.c \
	validations/mx_ls_valid_name.c \
	mx_ls.c \
	mx_ls_loop.c \
	main.c)

OBJ = \
	mx_ls_create_flags_str.o \
	mx_ls_create_main.o \
	mx_ls_create_param_arr.o \
	mx_ls_create_struct_arr.o \
	mx_ls_create_struct_print_l.o \
	mx_ls_insert_lstat.o \
	mx_ls_get_acl_inf.o \
	mx_ls_get_color.o \
	mx_ls_get_gid_name.o \
	mx_ls_get_hidden.o \
	mx_ls_get_ino_dev_fd.o \
	mx_ls_get_lstat.o \
	mx_ls_get_print_name.o \
	mx_ls_get_rwx_str.o \
	mx_ls_get_terminal_width.o \
	mx_ls_get_time_str.o \
	mx_ls_get_type.o \
	mx_ls_get_uid_name.o \
	mx_ls_get_xattr.o \
	mx_ls_read_dir.o \
	mx_ls_print_big_c.o \
	mx_ls_print_color.o \
	mx_ls_print_l.o \
	mx_ls_print_link_name.o \
	mx_ls_print_m.o \
	mx_ls_print_one.o \
	mx_ls_print_rwx.o \
	mx_ls_print.o \
	mx_ls_sort_default.o \
	mx_ls_sort_flag_big_s.o \
	mx_ls_sort_flag_c.o \
	mx_ls_sort_flag_r.o \
	mx_ls_sort_flag_t.o \
	mx_ls_sort_flag_u.o \
	mx_ls_sort.o \
	mx_until_check_flag.o \
	mx_until_create_char_arr.o \
	mx_until_del_tls.o \
	mx_until_files_in_dir.o \
	mx_until_get_len_number.o \
	mx_until_get_max_nlink.o \
	mx_until_get_max_size.o \
	mx_until_get_size_arr.o \
	mx_until_major_minor.o \
	mx_until_max_gid_str.o \
	mx_until_max_uid_str.o \
	mx_until_print_format_str.o \
	mx_ls_check_character_files.o \
	mx_ls_clear_flags.o \
	mx_ls_error.o \
	mx_ls_valid_flags.o \
	mx_ls_valid_name.o \
	mx_ls.o \
	mx_ls_loop.o \
	main.o

CC = clang

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all : install

install : libmx/libmx.a uls

libmx/libmx.a:
	@make -C $(LIBMXF)

uls : $(SRC) inc/uls.h libmx/libmx.a
	@$(CC) $(CFLAGS) -c $(SRC) $(foreach d, $(INC), -I $d)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

uninstall : clean
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean :
	@make clean -C $(LIBMXF)
	@rm -rf $(OBJ_DIR)

reinstall : uninstall install