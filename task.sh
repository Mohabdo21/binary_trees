#!/bin/bash

# print exit message
function exit_message {
	if [ $? -eq 0 ]; then
		echo -e "\033[1;32m"
		echo "============================================================="
		echo -e "Thank you for using the 0x1D. C - Binary trees project script\n"
		echo -e "Authors:\n- Mohamed Elfadil Ali\n- Mohannad Babeker\n"
		echo "============================================================="
		echo -e "\033[0m"
	fi
}
# whenever the script exits
trap exit_message EXIT

# Mapping task numbers to file numbers and descriptions
declare -A map=( [0]="0:Function that creates a binary tree node"
				 [1]="1:Function that inserts a node as the left-child of another node"
				 [2]="2:Function that inserts a node as the right-child of another node"
				 [3]="3:Function that deletes an entire binary tree"
				 [4]="4:Function that checks if a node is a leaf"
				 [5]="5:Function that checks if a given node is a root"
				 [6]="6:Function that goes through a binary tree using pre-order traversal"
				 [7]="7:Function that goes through a binary tree using in-order traversal"
				 [8]="8:Function that goes through a binary tree using post-order traversal"
				 [9]="9:Function that measures the height of a binary tree"
				 [10]="10:Function that measures the depth of a node in a binary tree"
				 [11]="11:Function that measures the size of a binary tree"
				 [12]="12:Function that counts the leaves in a binary tree"
				 [13]="13:Function that counts the nodes with at least 1 child in a binary tree"
				 [14]="14:Function that measures the balance factor of a binary tree"
				 [15]="15:Function that checks if a binary tree is full"
				 [16]="16:Function that checks if a binary tree is perfect"
				 [17]="17:Function that finds the sibling of a node"
				 [18]="18:Function that finds the uncle of a node"
				 [19]="100:Function that finds the lowest common ancestor of two nodes"
				 [20]="101:Function that goes through a binary tree using level-order traversal"
				 [21]="102:Function that checks if a binary tree is complete"
				 [22]="103:Function that performs a left-rotation on a binary tree"
				 [23]="104:Function that performs a right-rotation on a binary tree"
				 [24]="110:Function that checks if a binary tree is a valid Binary Search Tree"
				 [25]="111:Function that inserts a value in a Binary Search Tree"
				 [26]="112:Function that builds a Binary Search Tree from an array"
				 [27]="113:Function that searches for a value in a Binary Search Tree"
				 [28]="114:Function that removes a node from a Binary Search Tree"
				 [29]="115-O:Average time complexities on BST"
				 [30]="120:Function that checks if a binary tree is a valid AVL Tree"
				 [31]="121:Function that inserts a value in an AVL Tree"
				 [32]="122:Function that builds an AVL tree from an array"
				 [33]="123:Function that removes a node from an AVL tree"
				 [34]="124:Function that builds an AVL tree from an array"
				 [35]="125-O:Average time complexities on AVL Tree"
				 [36]="130:Function that checks if a binary tree is a valid Max Binary Heap"
				 [37]="131:Function that inserts a value in Max Binary Heap"
				 [38]="132:Function that builds a Max Binary Heap tree from an array"
				 [39]="133:Function that extracts the root node of a Max Binary Heap"
				 [40]="134:Function that converts a Binary Max Heap to a sorted array of integers"
				 [41]="135-O:Average time complexities on a Binary Heap" )

# Interactive mode
if [ "$#" -ne 1 ]; then
	while true; do
		echo "Select a subject:"
		echo "1) Regular Trees Operations."
		echo "2) BST Operations."
		echo "3) AVL Operations."
		echo "4) Heap Operations."
		echo "5) Exit."
		read -r -p "Enter your choice: " choice

		case $choice in
			1) TASK_NUMS=(0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23);;
			2) TASK_NUMS=(24 25 26 27 28 29);;
			3) TASK_NUMS=(30 31 32 33 34 35);;
			4) TASK_NUMS=(36 37 38 39 40 41);;
			5) exit 0;;
			*) echo "Invalid choice"; continue;;
		esac

			while true; do
				echo "Select a task:"
				for i in "${!TASK_NUMS[@]}"; do
					echo "$((i+1)): ${map[${TASK_NUMS[$i]}]#*:}"
				done
				read -r -p "Enter your choice: " task_choice

				if ! [[ $task_choice =~ ^[0-9]+$ ]]; then
					echo "Invalid input: Please enter a number."
					continue
				fi

				if [ "$task_choice" -lt 1 ] || [ "$task_choice" -gt "${#TASK_NUMS[@]}" ]; then
					echo "Invalid task number: Please enter a number between 1 and ${#TASK_NUMS[@]}."
					continue
				fi
				TASK_NUM=${TASK_NUMS[$((task_choice-1))]}
				break 2
			done
	done
else
	# Get the task number
	TASK_NUM=$1
fi

# if the task number not exists in the map
if [[ ! -v "map[$TASK_NUM]" ]]; then
	echo "Invalid task number: $TASK_NUM"
	exit 1
fi

# get the file number and description
FILE_NUM=${map[$TASK_NUM]%%:*}
DESCRIPTION=${map[$TASK_NUM]#*:}

echo "Task $TASK_NUM: $DESCRIPTION"

# check if the file is a text file
if [[ "$FILE_NUM" == *"-O" ]]; then
	echo "Displaying contents of text file $FILE_NUM:"
	cat "$FILE_NUM"
	exit 0
fi

echo "Compiling task $TASK_NUM"

# make command and suppress its output
make task TASK_NUM="$FILE_NUM" > /dev/null 2>&1

# if the make command was successful
if [ $? -eq 0 ]; then
	./binary_trees
	make -s clean > /dev/null 2>&1
else
	echo "Make command failed. Please check task number or Makefile."
fi
