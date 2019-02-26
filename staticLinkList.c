#include <stdio.h>
#include "Header.h"
//
void reserveArr(component *_array) {
	for (int i = 0; i < (MAXSIZE); i++) {
		_array[i].cur = (i + 1);
	}
	_array[MAXSIZE - 1].cur = 0;
}
//
int mallArr(component *_array) {
	int i = _array[0].cur;
	//
	if (_array[0].cur) {
		_array[0].cur = _array[i].cur;
	}
	return i;
}
//
int initArr(component *_array) {
	reserveArr(_array);
	int body = mallArr(_array);
	int tmpBody = body;
	for (int i = 1; i < 4; i++) {
		int j = mallArr(_array);
		_array[tmpBody].cur = j;
		_array[j].data = i;
		tmpBody = j;
	}
	_array[tmpBody].cur = 0;
	return body;
}
//
void dplArr(component *_array, int body) {
	int tmpBody = body;
	while (_array[tmpBody].cur) {
		printf("%d, %d | ", _array[tmpBody].data, _array[tmpBody].cur);
		tmpBody = _array[tmpBody].cur;
	}
	printf("%d, %d | \n", _array[tmpBody].data, _array[tmpBody].cur);
}
//
int main() {
	component array[MAXSIZE];
	int body = initArr(array);
	printf("-----: \n");
	dplArr(array, body);
	getchar();
	return 0;
}