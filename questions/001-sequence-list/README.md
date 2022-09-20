# 顺序表

## 题目

1. 设顺序表 `va` 中的数据元素递增有序。试写一算法，将 `x` 插入到顺序表的适当位置上，以保持该表的有序性。
2. 试写一算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表 `(a1, a2, ..., an)` 逆置为 `(an, an-1, ..., a1)` 。

## 数据定义

```c
typedef struct {
    DataType* data;
    int length;
    int maxSize;
} SeqList;
```

## 相关函数

```c
/**
 * @description: 初始化顺序表
 * @param {SeqList*} list 存放初始化后顺序表的对象。
 * @param {int} size 顺序表的大小。
 * @return {State} 分配内存失败返回 ERROR 否则返回 OK 。
 */
State createSeqList(SeqList* list, int size);


/**
 * @description: 输出顺序表中的数据。
 * @param {SeqList*} list 顺序表对象。
 * @return {State} list 对象为空返回 ERROR 否则返回 OK 。
 */
State printSeqList(SeqList* list)


/**
 * @description: 向顺序表末尾添加元素。
 * @param {SeqList*} list 要操作的顺序表对象。
 * @param {DataType} element 要添加的元素。
 * @return {State} 如果顺序表已满则返回 ERROR 否则返回 OK 。
 */
State pushElement(SeqList* list, DataType element)
```
