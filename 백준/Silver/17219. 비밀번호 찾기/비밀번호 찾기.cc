#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> site;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string address, password;
		cin >> address >> password;
		site.insert({ address,password });
	}
	for (int i = 0; i < M; i++) {
		string address;
		cin >> address;
		cout << site[address] << '\n';
	}
}