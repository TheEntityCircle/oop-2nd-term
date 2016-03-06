#include<stdio.h>

// Include our custom header
#include "linked_list.h"

int main()
{
	list_element* root = create_new_element(-1);

	list_element* new_elem;
	int i;
	for(i = 0; i < 10; i++) {
		new_elem = create_new_element(i);
		insert_into_list(new_elem, root);
	}

	print_list(root);

	int value = 10;

	if( search_by_value(root, value) == 0 ) {
		printf("Value %d exists in the list\n", value);
	} else {
		printf("There is no value %d in the list\n", value);
	}

	return 0;
}
