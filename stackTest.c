#include "expr_assert.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>


void test_create_a_stack_with_top_points_to_NULL(){
	Stack createdStack;
	createdStack = createStack();

	assertEqual(*(int*)createdStack.top,0);
};

void test_create_a_stack_with_top_points_to_NULL_and_noOfElements_0(){
	Stack createdStack;
	createdStack = createStack();

	assertEqual((int)createdStack.list->count,0);
};

void test_stack_top_points_to_the_data_12(){
	Stack stack = createStack();
	int data = 12,count,element;

	count = push(stack,&data);
	assertEqual(count,1);
	assertEqual(*(int*)(*stack.top)->data,data);
};

void test_stack_top_points_to_the_data_15(){
	Stack stack = createStack();
	int data[] = {12,15},count,element;

	count = push(stack,&data[0]);
	count = push(stack,&data[1]);

	assertEqual(count,2);
	assertEqual(*(int*)(*stack.top)->data,data[1]);
};

void test_push_puts_the_data_in_top_of_stack_and_return_hello_at_top(){
	Stack stack = createStack();
	char* data = "hello";
	char* result;
	int count;
	count = push(stack,&data);
	result = *(char**)(*stack.top)->data;

	assertEqual(strcmp(data,result),0);
	assertEqual(count,1);
}

void test_stack_gives_data_15_at_index_2(){
	Stack stack = createStack();
	int data[] = {12,13,15,16},count,index,i;

	for(i=0;i<4;i++){
		count = push(stack,&data[i]);
	}

	index = indexOf(*stack.list,&data[2]);

	assertEqual(count,4);
	assertEqual(index,2);
	assertEqual(*(int*)(*stack.top)->data,data[3]);
};

void test_stack_gives_data_c_at_top_and_count_5(){
	Stack stack = createStack();
	char data[] = {'a','b','c','d','e'},count,index,i;

	for(i=0;i<5;i++){
		count = push(stack,&data[i]);
	}

	index = *(char*)getElementAt(*stack.list,2);
	assertEqual(count,5);
	assertEqual(index,'c');
	assertEqual(*(char*)(*stack.top)->data,data[4]);
};

void test_pop_gives_reference_of_16_after_pop(){
	Stack stack = createStack();
	int data[] = {12,13,15,16},count,index,i;
	Node_ptr result;
	for(i=0;i<4;i++){
		count = push(stack,&data[i]);
	}
	result = pop(stack);
	assertEqual(*(int*)result,16);
	assertEqual(*(int*)(*stack.top)->data,data[2]);
};