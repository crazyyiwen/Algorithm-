#pragma once
#define MAXSIZE 6
typedef struct {
	int data;
	int cur;
}component;

void reserveArr(component *_array);

int initArr(component *_array);

void dplArr(component *_array, int body);

int mallArr(component *_array);
