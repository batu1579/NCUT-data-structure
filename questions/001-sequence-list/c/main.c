#include <stdio.h>

#include "../../define/c/util.h"
#include "./library/SeqList.c"

typedef int DataType;

State insertElement(SeqList* list, DataType element);

void switchTwoElement(DataType* a, DataType* b);

int main() {
	SeqList list1;
	initSeqList(&list1, 0);

	pushElement(&list1, 1);
	pushElement(&list1, 2);
	pushElement(&list1, 4);
	pushElement(&list1, 6);

	insertElement(&list1, 7);
	reverseElement(&list1);

	printSeqList(&list1);

	return 0;
}

State insertElement(SeqList* list, DataType element) {
	// 没有空间存放更多元素
	if (list->length == list->maxSize) {
		return ERROR;
	}

	for (int i = list->length; i > 0; i--) {
		if (element > list->data[i - 1]) {
			list->data[i] = element;
			list->length += 1;
			break;
		}
		list->data[i] = list->data[i - 1];
	}

	return OK;
}

State reverseElement(SeqList* list) {
	DataType* front = list->data;
	DataType* end = list->data + (list->length - 1);

	for (; front <= end;) {
		switchTwoElement(front, end);

		front += 1;
		end -= 1;
	}

	return OK;
}

void switchTwoElement(DataType* a, DataType* b) {
	DataType temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
