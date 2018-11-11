#include <stdlib.h>
#include"stack.h"
#include <string.h>

void init(stack *s) {
	*s = NULL;
}

int isempty(stack *s) {
	return *s == NULL;
}

int isfull(stack *s) {
	return 0;
}

void push(stack *s, char *name) {
	node *temp = (node *) malloc(sizeof(node));
	node *tempnode = *s;
	temp->name = (char *)malloc(sizeof(char) * 64);
	strcpy(temp->name, name);
	temp->next = NULL;
	if(!*s)
		*s = temp;
	else {
		while(tempnode->next)
			tempnode = tempnode->next;
		tempnode->next = temp;
	}
}

char *pop(stack *s) {
	char *ret;
	node *temp = *s;
	if((*s)->next == NULL) {
		ret = (*s)->name;
		free(*s);
		*s = NULL;
	}
	else {
		while(temp->next->next)
			temp = temp->next;
		ret = temp->next->name;
		free(temp->next);
		temp->next = NULL;
	}
	return ret;
}

