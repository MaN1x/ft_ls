project(ft_ls C)

set(CMAKE_C_STANDARD 99)

set(SOURCE main.c check_args.c scan.c print_dir.c scan_utilities.c scan_utilities.h dir_utilities/sort_dir_list.c dir_utilities/free_dir_list.c dir_utilities/dir_new.c dir_utilities/dir_add.c dir_utilities/dir_getend.c dir_utilities/file_utilities/free_files.c dir_utilities/file_utilities/file_new.c dir_utilities/file_utilities/file_add.c dir_utilities/dir_list_size.c dir_utilities/dir_list_swap.c dir_utilities/file_utilities/sort_file_list.c dir_utilities/file_utilities/file_list_size.c dir_utilities/file_utilities/file_list_swap.c dir_utilities/file_utilities/file_size.c print_assist.c)

set(SOURCE_LIB  ./lib/ft_atoi.c
                ./lib/ft_bzero.c
                ./lib/ft_isalnum.c
                ./lib/ft_isalpha.c
                ./lib/ft_isascii.c
                ./lib/ft_isdigit.c
                ./lib/ft_isprint.c
                ./lib/ft_itoa.c
                ./lib/ft_lst_n.c
                ./lib/ft_lstadd.c
                ./lib/ft_lstaddend.c
                ./lib/ft_lstaddn.c
                ./lib/ft_lstdel.c
                ./lib/ft_lstdelh.c
                ./lib/ft_lstdelone.c
                ./lib/ft_lstiter.c
                ./lib/ft_lstmap.c
                ./lib/ft_lstnew.c
                ./lib/ft_lstsize.c
                ./lib/ft_memalloc.c
                ./lib/ft_memccpy.c
                ./lib/ft_memchr.c
                ./lib/ft_memcmp.c
                ./lib/ft_memcpy.c
                ./lib/ft_memdel.c
                ./lib/ft_memmove.c
                ./lib/ft_memset.c
                ./lib/ft_putchar.c
                ./lib/ft_putchar_fd.c
                ./lib/ft_putendl.c
                ./lib/ft_putendl_fd.c
                ./lib/ft_strcat.c
                ./lib/ft_strchr.c
                ./lib/ft_strclr.c
                ./lib/ft_strcmp.c
                ./lib/ft_strcpy.c
                ./lib/ft_strdel.c
                ./lib/ft_strdup.c
                ./lib/ft_strequ.c
                ./lib/ft_striter.c
                ./lib/ft_striteri.c
                ./lib/ft_strjoin.c
                ./lib/ft_strlcat.c
                ./lib/ft_strlen.c
                ./lib/ft_strmap.c
                ./lib/ft_strmapi.c
                ./lib/ft_strncat.c
                ./lib/ft_strncmp.c
                ./lib/ft_strncpy.c
                ./lib/ft_strnequ.c
                ./lib/ft_strnew.c
                ./lib/ft_strnstr.c
                ./lib/ft_strrchr.c
                ./lib/ft_strsplit.c
                ./lib/ft_strstr.c
                ./lib/ft_strsub.c
                ./lib/ft_strtrim.c
                ./lib/ft_tolower.c
                ./lib/ft_toupper.c
                ./lib/ft_putnbr.c
                ./lib/ft_putnbr_fd.c
                ./lib/ft_putstr.c
                ./lib/ft_putstr_fd.c
                ./lib/ft_lstswap.c
                ./lib/ft_putspace.c)

add_library(libft STATIC ${SOURCE_LIB})

add_executable(ft_ls ${SOURCE})

target_link_libraries(ft_ls libft)
