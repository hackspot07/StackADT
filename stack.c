#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(){
	Stack stack_list;
	LinkedList* list = calloc(sizeof(LinkedList),1);
	stack_list.list = list;
	stack_list.top = &list->tail;
	return stack_list;
};

int push(Stack stack, void* data){
	Node_ptr newNode = create_node(data);
	int yes = add_to_list(stack.list,newNode);
	return (yes)?stack.list->count:-1;
};

void * pop(Stack stack){
	return deleteElementAt(stack.list,stack.list->count-1);
};