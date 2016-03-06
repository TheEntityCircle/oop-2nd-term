#include<stdio.h>
#include<stdlib.h>

// Struct to store list element
typedef struct list_element {
	int value;			// Element value
	struct list_element* next;	// Pointer to next element
} list_element;

// Create new element, set its value to 'i', return pointer to new element
list_element* create_new_element(int i)
{
	// Allocate memmory
	list_element* elem = (list_element*)malloc(sizeof(list_element));
	// Set value
	elem->value = i;
	// There is no next element, so set next to NULL
	elem->next = NULL;

	return elem;
}

// Insert element 'elem' into list 'root' (on the 2nd position)
list_element* insert_into_list(list_element* root, list_element* elem)
{
	// Next after new element - former root
	elem->next = root;
	// New element becomes new root
	return elem;
}

// Print list
void print_list(list_element* cur_element)
{
	// Iterate through elements while NULL is not found
	while(cur_element != NULL) {
		printf("Element: %d\n", cur_element->value);
		// Go to next element
		cur_element = cur_element->next;
	}
}

// Search for given value in the list
// Returns pointer to found element and NULL otherwise
list_element* search_by_value(list_element* root, int value)
{
	while(root != NULL) {
		if(root->value == value)
			return root;
		root = root->next;
	}
	return NULL;
}

// Returns pointer to element with number 'index'
// or NULL if index is out of range
list_element* get_by_index(list_element* root, int index)
{
	int i;
	if(index < 0)
		return NULL;

	for(i = 0; i < index; i++) {
		if(root == NULL)
			return NULL;
		root = root->next;
	}

	return root;
}

// Deletes element from list
list_element* delete_from_list(list_element* root, list_element* elem)
{
	// Special case - we are to delete the first element
	if(root == elem)
	{
		// remember new root element
		list_element* new_root = root->next;
		// free memory
		free(root);
		// return new root
		return new_root;
	}

	// Loop through the list.
	// Stop if either (a) it's the end of the list or (b) the next element is the one to delete.
	while( (root != NULL) && (root->next != elem))
	{
		root = root->next;
	}

	// If we reached the end of the list (case 'a' above) - return NULL 
	// (we consider it as an error code for 'incorrect deletion request').
	if(root == NULL)
	{
		return NULL;
	}

	// If we found the element to delete (case 'b' avove):
	// - change pointers
	root->next = elem->next;
	// - free memory
	free(elem);
	// - return old root (just to make function behaviour consistent)
	return root;
}
