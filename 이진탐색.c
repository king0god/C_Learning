#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// �̺� Ž��, ���� Ž�� : ���ĵ� �迭�� ������ ã��

int arr[100] = { 5, 7, 33, 66, 67, 88, 99, 120, 134, 156, 201 };
int n, k; // k�� ���� ã�� ����
int count = 0;
int check = 1; // ã���� ��ã���� Ȯ��
int binarysearch(int s, int e) { // start end
	while (s <= e) {
		int m = (s + e) / 2; // m�� middle
		if (arr[m] == k) {
			++count;
			return count; // ã�� �迭�� �ε���(��ġ)
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
	return count;// �ᱹ ��ã��
}

int main() {
	printf("ã�� ���� �Է� : ");
	scanf("%d", &k); // k == 66;
	int i = binarysearch(0, 10);
	if (check == 2) {
		printf("%d������ ��ã�ҽ��ϴ�", i);
	}
	else{
		printf("%d������ ã�ҽ��ϴ�.", i);
	}

	return 0;
}
/********************����*******************/
//  �� ������ ã�Ҵ��� count ������
//  ����ϵ��� �ڵ带 ���� �Ǵ� �߰� �Ͻÿ�.
//  ��) 12������ ã�ҽ��ϴ�.
//  ��) 25������ ��ã�ҽ��ϴ�.
/*******************************************/