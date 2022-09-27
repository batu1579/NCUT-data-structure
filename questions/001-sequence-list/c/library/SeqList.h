#pragma once
#define DEFAULT_MAX_SIZE 20 

typedef struct {
	DataType* data;
	int length;
	int maxSize;
} SeqList;