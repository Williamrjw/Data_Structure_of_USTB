#include <iostream>
#include <stack>
using namespace std;
struct BT {
	char data;
	BT* left;
	BT* right;
};
BT* find(BT *T, char parent) {
	stack<BT *> stk;
	BT* p = T;
	while (!stk.empty())stk.pop();
	///////////////
	while (p || !stk.empty()) {
		while (p) {
			if (parent == p->data) { return p; }
			if (NULL != p->right) {
				if (parent == p->right->data) { return p->right; }
				stk.push(p->right);
			}
			if (NULL != p->left)
			if (parent == p->left->data) { return p->left; }
			p = p->left;
		}
		if (!stk.empty()) { p = stk.top(); stk.pop(); }
	}
	////////////
}
void print(BT* T) {
	if (NULL != T) {
		cout << T->data;
	}
	if (NULL == T->left&& NULL == T->right) return;
	cout << '(';
	if (NULL != T->left) {
		print(T->left);
	}
	if (NULL != T->right) {
        cout << ',';
		print(T->right);
	}
	cout << ')';
	return;
}
void pregnancy(BT* T, char offspring, char lr) {
	if ('L' == lr) {
		T->left = new BT;
		T->left->data = offspring;
		T->left->left = NULL;
		T->left->right = NULL;
	}
	if ('R' == lr) {
		T->right = new BT;
		T->right->data = offspring;
		T->right->left = NULL;
		T->right->right = NULL;
	}
}
int main() {
	char f, c, lr;
	cin >> f >> c >> lr;
    if('^' == f && '^' == c)return 0;
	BT* T = new BT;
	T->data = 0;
	T->left = NULL;
	T->right = NULL;
	while (!('^' == f && '^' == c)) {
		if ('^' == f) {
			T->data = c;
		}
		else {
			pregnancy(find(T, f), c, lr);
		}
		cin >> f >> c >> lr;
	}
	print(T);
	return 0;
}