#include <iostream>
#include <math.h>

using namespace std;

/*
1. 1

2. 1 1

3. 1 1 1 // 1 추가 (1자리 늘어남, 3자리를 가지고 이거 포함 앞으로 2줄 버팀)
4. 1 2 1

5. 1 1 2 1 // 1 추가 (1자리 늘어남, 4자리를 가지고 이거 포함 앞으로 2줄 버팀)
6. 1 2 2 1
7. 1 1 2 2 1 // 1 추가 (1자리 늘어남, 5자리를 가지고 이거 포함 앞으로 3줄 버팀)
8. 1 2 2 2 1
9. 1 2 3 2 1

10. 1 1 2 3 2 1 // 1 추가 (1자리 늘어남, 6자리를 가지고 이거 포함 앞으로 3줄 버팀)
11. 1 2 2 3 2 1
12. 1 2 3 3 2 1
13. 1 1 2 3 3 2 1 // 1 추가 (1자리 늘어남, 7자리를 가지고 이거 포함 앞으로 4줄 버팀)
14. 1 2 2 3 3 2 1
15. 1 2 3 3 3 2 1
16. 1 2 3 4 3 2 1

17. 1 1 2 3 4 3 2 1 // 1 추가 
18. 1 2 2 3 4 3 2 1
19. ...

규칙을 찾아보면,

작동 횟수 / 범위 크기 / 거리
		1				1					1*
		2				1					2
		3				2					3-4*
		4				2					5-6
		5				3					7-9*
		6				3					10-12
		7				4					13-16*
		8				4					17-20
		9				5					21-25*
		10			5					26-30
		11			6					31-36*
		12			6					37-42
*/

int fly(int a,int b) {
	/*
	parameters
	a : 현재 위치
	b : 목표 위치

	reterns
	result : 공간이동 장치의 최소 작동 횟수
	*/

	int dist = b - a;
	double sqrtDist = sqrt(dist);
	int sqrtDistInt = floor(sqrtDist);
	int result = 0;
	if (sqrtDist == sqrtDistInt) {
		result = (sqrtDistInt * 2) - 1;
	} else if ((dist > pow(sqrtDistInt, 2)) && (dist < sqrtDistInt * (sqrtDistInt + 1))) {
		result = (sqrtDistInt * 2);
	} else {
		result = (sqrtDistInt * 2) + 1;
	}
	return result;
}

int main() {
	int caseNum;
	cin >> caseNum;

	int a;
	int b;

	for (int i = 0; i < caseNum; i++) {
		cin >> a >> b;
		cout << fly(a, b) << endl;
	}
	return 0;
}