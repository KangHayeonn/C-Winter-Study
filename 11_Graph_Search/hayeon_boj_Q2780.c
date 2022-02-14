// 비밀번호 (백준 2780번)

/* [ 알고리즘 ]
 *
 * 1. 0~9까지 인접한 값을 케이스로 나눠준다. ex 0 -> 7 , 5 -> 2, 4, 6, 8
 * 2. 예를 들어, 0에서 시작한 숫자가 4자리 수일 경우 (이때, 0에서 4자리 수일 때의 값을 저장)
 * 3. 0과 인접한 7로 넘어간 뒤 3자리 숫자로 변경한다.(이때, 7에서 3자리 수일 때의 값을 저장)
 * 4. 다음으로 7과 인접한 4, 8, 0 숫자로 넘어간 뒤 2자리 숫자로 변경한다. (이때, 4, 8, 0에서 2자리 수일 때의 값을 저장)
 * 5. 마지막으로 4, 8, 0과 인접한 숫자 (1,5,7) , (5,7,9) , (7) 과 인접한 숫자로 넘어간 뒤 1자리 숫자로 변경한다. (이때, 각각의 경우에서 1자리 수일 때의 값을 저장)
 * 6. 마지막으로 1자리 숫자만 남았을 경우 +1한 값을 리턴해준다.
 * 7. 2-6번의 과정을 재귀로 구현
 *
 * (만약, for문을 이용해 구현하고 싶다면 0~9까지의 숫자가 1자리 수일 경우 1을 먼저 저장해준 뒤, 자리 수가 늘어날 때마다 저장된 메모이제이션 값을 불러와서 추가해줌)
 */

#include <stdio.h>

int dp[10][1001] = { -1, }; // 메모이제이션 된 값 ([숫자][길이])

int FindPW(int num, int maxCount);

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int maxCount;
		scanf("%d", &maxCount);
		int count = 0; // 초기화 안되서 자꾸 값이 추가된 값이 BufferedWriter에 저장됨

		for (int num = 0; num < 10; num++) {
			count += FindPW(num, maxCount);
		}
		printf("%d\n", (count % 1234567));
	}
}

int FindPW(int num, int maxCount) {

	int count = 0;

	if (maxCount == 1) {
		count = count + 1;
	}
	else if (dp[num][maxCount] > 0) { // 이미 저장된 값이 있다면 메모이제이션 값 그대로 사용
		return dp[num][maxCount];
	}
	else {
		// 저장된 값 없고 아직 2자리 수 이상임
		switch (num) {
		case 0: {
			count += FindPW(7, maxCount - 1);
			break;
		}
		case 1: {
			count += FindPW(2, maxCount - 1) + FindPW(4, maxCount - 1);
			break;
		}
		case 2: {
			count += FindPW(1, maxCount - 1) + FindPW(3, maxCount - 1) + FindPW(5, maxCount - 1);
			break;
		}
		case 3: {
			count += FindPW(2, maxCount - 1) + FindPW(6, maxCount - 1);
			break;
		}
		case 4: {
			count += FindPW(1, maxCount - 1) + FindPW(5, maxCount - 1) + FindPW(7, maxCount - 1);
			break;
		}
		case 5: {
			count += FindPW(2, maxCount - 1) + FindPW(4, maxCount - 1) + FindPW(6, maxCount - 1) + FindPW(8, maxCount - 1);
			break;
		}
		case 6: {
			count += FindPW(3, maxCount - 1) + FindPW(5, maxCount - 1) + FindPW(9, maxCount - 1);
			break;
		}
		case 7: {
			count += FindPW(0, maxCount - 1) + FindPW(4, maxCount - 1) + FindPW(8, maxCount - 1);
			break;
		}
		case 8: {
			count += FindPW(5, maxCount - 1) + FindPW(7, maxCount - 1) + FindPW(9, maxCount - 1);
			break;
		}
		case 9: {
			count += FindPW(6, maxCount - 1) + FindPW(8, maxCount - 1);
			break;
		}
		default: break;
		}
	}

	count = count % 1234567;
	dp[num][maxCount] = count;
	return count;
}