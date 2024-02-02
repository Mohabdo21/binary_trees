# Makefile for all tasks
# usage
# make task TASK_NUM=<task_number> && ./binary_trees && make -s clean

# the compiler to be used
CC = gcc
# Common files
COMMON = 0-binary_tree_node.c binary_tree_print.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c 3-binary_tree_delete.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 111-bst_insert.c 112-array_to_bst.c 121-avl_insert.c 122-array_to_avl.c 123-avl_remove.c 131-heap_insert.c 132-array_to_heap.c 133-heap_extract.c



# Task files - the rest are in common due to repetitive use
0 = main_files/0-main.c
1 = main_files/1-main.c #
2 = main_files/2-main.c #
3 = main_files/3-main.c # 
4 = 4-binary_tree_is_leaf.c main_files/4-main.c 
5 = 5-binary_tree_is_root.c main_files/5-main.c 
6 = 6-binary_tree_preorder.c main_files/6-main.c 
7 = 7-binary_tree_inorder.c main_files/7-main.c
8 = 8-binary_tree_postorder.c main_files/8-main.c 
9 = 9-binary_tree_height.c main_files/9-main.c 
10 = 10-binary_tree_depth.c main_files/10-main.c 
11 = 11-binary_tree_size.c main_files/11-main.c 
12 = 12-binary_tree_leaves.c  main_files/12-main.c  
13 = 13-binary_tree_nodes.c main_files/13-main.c 
14 = main_files/14-main.c #
15 = 15-binary_tree_is_full.c main_files/15-main.c 
16 = 16-binary_tree_is_perfect.c  main_files/16-main.c  
17 = 17-binary_tree_sibling.c main_files/17-main.c 
18 = 18-binary_tree_uncle.c main_files/18-main.c 
100 = 100-binary_trees_ancestor.c main_files/100-main.c 
101 = 101-binary_tree_levelorder.c main_files/101-main.c 
102 = 102-binary_tree_is_complete.c main_files/102-main.c 
103 = main_files/103-main.c #
104 = main_files/104-main.c #
110 = 110-binary_tree_is_bst.c main_files/110-main.c 
111 = main_files/111-main.c #
112 = main_files/112-main.c #
113 = 113-bst_search.c main_files/113-main.c 
114 = 114-bst_remove.c main_files/114-main.c 
120 = 120-binary_tree_is_avl.c main_files/120-main.c 
121 = main_files/121-main.c #
122 = main_files/122-main.c #
123 = main_files/123-main.c #
124 = 124-sorted_array_to_avl.c main_files/124-main.c 
130 = 130-binary_tree_is_heap.c main_files/130-main.c 
131 = main_files/131-main.c #
132 = main_files/132-main.c #
133 = main_files/133-main.c #
134 = 134-heap_to_sorted_array.c main_files/134-main.c 


TASK_NUM ?= 0
TASK_VAR := $(shell echo '$($(TASK_NUM))')
MAIN := $(if $(TASK_VAR),$(TASK_VAR),invalid_task)

# MAIN := $(or $($TASK_NUM), invalid_task)
# MAIN := $(or $($TASK_NUM), $(error Invalid task number: $(TASK_NUM)))
# MAIN := $(or $($TASK_NUM), $(MAIN))
# the .c files
SRC = $(COMMON) $(MAIN)
# the .o files
# the name of the executable
NAME = binary_trees
# the program to delete files
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic

.PHONY: all binary_trees clean re task
# builds executable
# recompile only the updated source files
all: $(NAME)
# the name of the executable
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
# deletes all Emacs and Vim temporary files along with executable
clean:
	$(RM) $(NAME) *~ .*~ *.swp
# forces recompilation of all source files
re:	clean task

# allow the user to specify a task number and dynamically set MAIN
task:
	@if [ "$(MAIN)" = "invalid_task" ]; then \
		echo "Invalid task number: $(TASK_NUM)"; \
	else \
		echo -e "Building for task $(TASK_NUM): $(MAIN)\n\n"; \
		$(MAKE) all MAIN="$(MAIN)"; \
	fi

debug:
	@echo "TASK_NUM=$(TASK_NUM)"
	@echo "TASK_VAR=$(TASK_VAR)"
	@echo "MAIN=$(MAIN)"
