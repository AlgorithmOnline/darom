#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node() {
		val = 0;
		left = NULL;
		right = NULL;
	}
};
string preorder(Node* root) {
	string ans = "";
	ans += "V"; // 정점 방문 시작
	if (root->left) {
		ans += "L";
		ans += preorder(root->left);
		ans += "l";
	}
	if (root->right) {
		ans += "R";
		ans += preorder(root->right);
		ans += "r";
	}
	ans += "v"; // 끝
	return ans;
}
void remove(Node* root) {
	if (root->left) {
		remove(root->left);
	}
	if (root->right) {
		remove(root->right);
	}
	delete root;
}

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	set<string> s; // 중복되지 않는 원소 개수를 셀 때 유용
	// BST를 만들고, 프리오더한 결과가 다른 것이 몇 개 있는지 구하기
	for (int k = 0; k < n; k++) {
		vector<int> a(m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
		}
		// 트리 구성
		Node* root = new Node;
		root->val = a[0];
		for (int i = 1; i < m; i++) {
			Node* cur = root;
			// 삽입할 위치 찾기
			while (true) {
				if (cur->val > a[i]) {
					if (cur->left == NULL) {
						cur->left = new Node;
						cur->left->val = a[i];
						break;
					}
					else {
						cur = cur->left;
					}
				}
				else if (cur->val < a[i]) {
					if (cur->right == NULL) {
						cur->right = new Node;
						cur->right->val = a[i];
						break;
					}
					else {
						cur = cur->right;
					}
				}
				else {
					break;
				}
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	printf("%d", s.size());
	return 0;
}