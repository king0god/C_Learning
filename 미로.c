#include <stdio.h>
int m[9][9] = { //maze
             {2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej, success, idx, Path_i[100], Path_j[100];

//S : Start,출발점 E: End, 도착점, idx 경로 배열 인덱스
//Path_i, Path_j : 지나간 길을 저장함(i는 행, j는 열)

int visit(int, int);
int main() {
    idx = 0;//스택의 top 위치 저장
    success = 0;//미로 탈출 여부
    printf("=== 미로 탈출 경로 찾기 게임 ===\n");
    Si = 1, Sj = 1;//출발점
    Ei = 7, Ej = 7;//도착점
    if (visit(Si, Sj) == 0)
        printf("출구를 찾을 수 없음\n");
    else
        printf("모든 경로를 찾았음\n");
    return 0;
}
int visit(int i, int j) {
    static int path = 1;
    m[i][j] = 1;
    Path_i[idx] = i, Path_j[idx] = j;//경로 i,j를 저장
    idx++;

    if (i == Ei && j == Ej) {//도착점에 도착했을 때
        printf("찾은 경로 %d 번\n", path++);
        for (int k = 0; k < idx; k++)//경로 출력
            printf("(%d, %d) ", Path_i[k], Path_j[k]);
        printf("\n");
        success = 1;//경로를 성공적으로 찾음
    }

    /////미로 탐색 로직 만들기//////
    if (m[i][j + 1] == 0) //right
        visit(i, j + 1);
    if (m[i + 1][j] == 0) //down
        visit(i + 1, j);
    if (m[i][j - 1] == 0) //left
        visit(i, j - 1);
    if (m[i - 1][j] == 0) //up
        visit(i - 1, j);
    idx--;
    m[i][j] = 0;//경로 원상복귀
    return success;
}