#include "../LinkedListADT/linkedList.h"

typedef struct stack Stack;

struct stack{
	Node_ptr* top;
	LinkedList* list;
};

Stack createStack(void);
int push(Stack stack, void* data);
