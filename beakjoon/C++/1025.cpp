#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> select(int num1, int num2, int i, int j, vector<vector<int>> vec) {
	/*
	num1 : vec의 행 크기
	num2 : vec의 열 크기
	
	i : 행 공차의 절댓값
	j : 열 공차의 절댓값

	vec : 숫자를 가져올 2차원 벡터

	returns : 등차수열 idx를 만족하는 숫자
	*/

	vector<int> selected_vec;

	int arr_row_gongcha[2] = {i, -1 * i};
	int arr_col_gongcha[2] = {j, -1 * j};
	int row_idx = 0;
	int col_idx = 0;

	for (int n = 0; n < 10; n++){
		for (int k = 0; k < num1; k++) {
			for (int l = 0; l < num2; l++) {
				row_idx = n*i + k;
				col_idx = n*j + l;

				if (row_idx >= 0 && col_idx >= 0) {
					selected_vec.push_back(vec[row_idx][col_idx]);
				} else {
					return selected_vec;
				}
			}
		}
	}
}

int result1(vector<int> selected_vec) {
	int size = selected_vec.size();
	int last = 1;
	if (size == 0){
		return -1;
	} else {
		for (int i = 0; i < size; i++) {
			last = last + (selected_vec[i] * pow(10, (size - i - 1)));
			if (sqrt(last) == floor(sqrt(last))) {
				return last;
			} else {
				return -1;
			}
		}
	}
}

int main() {
	int num1; // 행 개수
	int num2; // 열 개수

	cin >> num1 >> num2;

	vector<vector<int>> vec(num1, vector<int>(num2, 0)); // 2차원 벡터 생성 및 0으로 초기화 (그래야 인덱스로 접근 가능)

	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			int a;
			cin >> a;
			vec[i][j] = a; // vec에 직접 cin으로 넣으면 오류 생길까?
		}
	}


	vector<int> selected_vec;
	vector<int> selected_vec2;

	for (int i = 0; i < num1; i++) { // 행에서의 공차 i의 절댓값은 0 <= i < num1 이다
		for (int j = 0; j < num2; j++) { // 열에서의 공차 j의 절댓값은 0 <= j < num2 이다
			// 숫자 선택하는 함수 - select
			selected_vec = select(num1, num2, i, j, vec);
			// 완전제곱수인지 확인

			// 있으면 출력

			// 없으면 -1

			selected_vec2.push_back(result1(selected_vec));
		}
	}
	
	int max = -1;

	for (int a = 0; a < selected_vec2.size(); a++) {
		if (selected_vec2[a] > max) {
			max = selected_vec2[a];
		}
	}


	if (max == -1) {
		cout << -1 << endl;
	} else {
		cout << max << endl;
	}
 	return 0;
}