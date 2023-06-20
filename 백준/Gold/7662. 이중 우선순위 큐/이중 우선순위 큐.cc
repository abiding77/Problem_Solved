#include <iostream>
#include <queue>
#include <set>

using namespace std;
/*
입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다. 이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다. ‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다. 동일한 정수가 삽입될 수 있음을 참고하기 바란다.
‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, 
‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다.
최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.

만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다. Q에 저장될 모든 정수는 -231 이상 231 미만인 정수이다.
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int k;
		cin >> k;
		multiset<int> PQ;
		multiset<int>::iterator iter;
		for (int i = 0; i < k; i++) {
			string s;
			int num;
			cin >> s;
			if (s == "I") {
				cin >> num;
				PQ.insert(num);
				//beginit++;
			}
			if (s == "D") {
				cin >> num;
				if (num == -1) {
					if (PQ.empty()) continue; // 비어있으면 무시
					else {
						PQ.erase(PQ.begin());
						//endit--;
					}
				}
				else {
					if (PQ.empty()) continue;
					else {
						PQ.erase(--PQ.end());
						//endit--;
					}
				}
			}
		}
		if (PQ.empty()) cout << "EMPTY" << '\n';
		else {
			iter = --PQ.end();
			cout << *iter << " ";
			iter = PQ.begin();
			cout << *iter << '\n';
		}
	}
	return 0;
}