#pragma once
#include<iostream>
#include<assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};
typedef struct Heap HP;

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustDown(HPDataType* a, int n, int parent);
void AdjustUp(HPDataType* a,int child);
//HP*HeapInit(HPDataType*a,int n);
void HeapInit(HP* php, HPDataType* a, int n);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php);