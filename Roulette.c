#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{false, true}bool;

typedef struct line {
	int No;
	struct line *next;
}line;

void initLine(line **head, int n) {
	*head = (line *)malloc(sizeof(line));
	(*head)->next = NULL;
	(*head)->No = 1;
	line *list = *head;
	for (int i = 1; i < n; i++) {
		line *body = (line*)malloc(sizeof(line));
		body->next = NULL;
		body->No = i + 1;
		list->next = body;
		list = list->next;
	}
	list->next = *head;
}

void display(line *head) {
	line *tmp = head;
	while (tmp->next != head) {
		printf("%d ", tmp->No);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->No);
}

int main() {
	line *head = NULL;
	srand((int)time(0));
	int n, shootNum, round = 1;
	printf("please input the number of gambler: ");
	scanf("%d ", &n);
	initLine(&head, n);
	line *lineNext = head;
	while (head->next != head) {
		printf("%d round begins  %d person begins ", round, lineNext->No);
		shootNum = rand() % n + 1;
		printf("gun %d\n", shootNum);
		line *tmp = lineNext;
		for (int i = 1; i < shootNum - 1; i++) {
			tmp = tmp->next;
		}

		printf("%d delete \n", tmp->next->No);
		line *del = tmp->next;
		tmp->next = tmp->next->next;
		if (del == head) {
			head = head->next;
		}
		free(del);
		display(head);
		lineNext = tmp->next;
		round++;
	}
	printf("the winner is %d\n", head->No);

	return 0;
}
