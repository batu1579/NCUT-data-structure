#include <stdio.h>
#include <malloc.h>

#include "./SeqList.h"
#include "../../define/c/util.h"

/**
 * @description: 初始化顺序表
 * @param {SeqList*} list 存放初始化后顺序表的对象。
 * @param {int} size 顺序表的大小。
 * @return {State} 分配内存失败返回 ERROR 否则返回 OK 。
 */
State initSeqList(SeqList* list, int size) {
	// size 不合法时使用默认值
	size = size <= 0 ? DEFAULT_MAX_SIZE : size;

	// 分配内存
	list->length = 0;
	list->maxSize = size;
	list->data = (DataType*)malloc(sizeof(DataType) * size);

	return list->data == NULL ? ERROR : OK;
}

/**
 * @description: 输出顺序表中的数据。
 * @param {SeqList*} list 顺序表对象。
 * @return {State} list 对象为空返回 ERROR 否则返回 OK 。
 */
State printSeqList(SeqList* list) {
	if (list->data == NULL) {
		return ERROR;
	}

	for (int i = 0; i < list->length; i++) {
		printf("%d", list->data[i]);
	}
	printf("\n");

	return OK;
}

/**
 * @description: 重新分配顺序表的空间。
 * @param {SeqList*} list 顺序表对象。
 * @param {int} newSize 要设置的新的大小。
 * @return {State} 分配是否成功。
 */
State resizeSeqList(SeqList* list, int newSize) {
	// 如果新的容量不合法则改为原来最大空间的二倍
	newSize = newSize < list->length ? list->maxSize * 2 : newSize;

	DataType* newList = (DataType*)realloc(list->data, newSize);

	if (newList == NULL) {
		return ERROR;
	}

	list->data = newList;
	list->maxSize = newSize;

	return OK;
}

/**
 * @description: 向顺序表末尾添加元素。
 * @param {SeqList*} list 要操作的顺序表对象。
 * @param {DataType} element 要添加的元素。
 * @return {State} 如果顺序表已满则返回 ERROR 否则返回 OK 。
 */
State pushElement(SeqList* list, DataType element) {
	if (list->length == list->maxSize) {
		return ERROR;
	}

	list->data[list->length] = element;
	list->length += 1;

	return OK;
}