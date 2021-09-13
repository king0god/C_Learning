#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int queue[5];
void menuf() {
	printf("\n1. 큐에 삽입 2. 큐에서 삭제\n");
	printf("3. 내용 보기 4. 종료\n");
} // 메뉴 함수
void Enqueue(int* back, int item) { // 큐에 삽입
	if (*back == 4) {
		printf("큐가 가득참\n");
		return;
	}
	queue[++ * back] = item;
}
int Dequeue(int* front, int back) {
	if (*front == back) {
		return -1;
	}
	return queue[++ * front];
}
void Display(int front, int back) {
	if (front == back) {
		printf("큐가 비었음\n");
	}
	for (int i = front + 1; i <= back; i++) {
		printf("%4d", queue[i]);
	}
}
int main() {
	int front = -1, back = -1;
	// queue : front, back, stack : top
	int menu, item;
	while (1) {
		menuf();
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			scanf("%d", &item);
			Enqueue(&back, item);
			break;
		case 2:
			item = Dequeue(&front, back);
			if (item == -1){
				printf("큐가 비었음");
			}
			else {
				printf("%d가 삭제됨\n",item);
			}
			break;
		case 3:
			Display(front, back); // 과제
			// 큐의 내용을 출력해 보시오.
			break;
		case 4:
			return 0;
		default:
			printf("다시 입력해주세요.");
		}
	}
}