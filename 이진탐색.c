#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 이분 탐색, 이진 탐색 : 정렬된 배열속 데이터 찾기

int arr[100] = { 5, 7, 33, 66, 67, 88, 99, 120, 134, 156, 201 };
int n, k; // k는 내가 찾을 숫자
int count = 0;
int check = 1; // 찾은지 못찾은지 확인
int binarysearch(int s, int e) { // start end
	while (s <= e) {
		int m = (s + e) / 2; // m은 middle
		if (arr[m] == k) {
			++count;
			return count; // 찾은 배열의 인덱스(위치)
		}
		if (arr[m] > k) {
			e = m - 1;
			count++;
		}
		else {
			s = m + 1;
			count++;
		}
	}
	++check;
	return count;// 결국 못찾음
}

int main() {
	printf("찾을 숫자 입력 : ");
	scanf("%d", &k); // k == 66;
	int i = binarysearch(0, 10);
	if (check == 2) {
		printf("%d번만에 못찾았습니다", i);
	}
	else{
		printf("%d번만에 찾았습니다.", i);
	}

	return 0;
}
/********************과제*******************/
//  몇 번만에 찾았는지 count 변수로
//  출력하도록 코드를 수정 또는 추가 하시오.
//  예) 12번만에 찾았습니다.
//  예) 25번만에 못찾았습니다.
/*******************************************/