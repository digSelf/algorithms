#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 5;
int Q[N], head, tail;

void init() {
	// tail指向的是尚未分配内存的地方
	head = tail = 0;
}

void push(int x) {
	Q[tail++] = x;
}

void pop() {
	++head;
}

bool empty() {
	return head >= tail; // 其实head == tail的时候就是空了
}

int query() {
	return Q[head];
}

int main() {
	std::ios::sync_with_stdio(false);
	
	init();

	int M; cin >> M;
	while (M --)
	{
		string op;
		int x;
		
		cin >> op;
		if (op == "push") {
			cin >> x;
			push(x);
		} else if (op == "pop") {
			pop();
		} else if (op == "empty") {
			if (empty())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else { // query
			cout << query() << endl;
		}
	}
	
	return 0;
}