#include <iostream>

class TRIE {
public:
	TRIE* child[26]; // a ~ z
	int cnt;

	TRIE() {
		for (int i = 0; i < 26; ++i) child[i] = nullptr;
		cnt = 0;
	}

	~TRIE() {
		for (int i = 0; i < 26; ++i) {
			if (child[i] != nullptr)
				delete(child[i]);
		}
	}
};

int n, ans;

void dfs(TRIE* A) {
	for (int i = 0; i < 26; i++) {
		TRIE* t = A->child[i];
		if (t == NULL) continue;
		dfs(t);
		if (t->cnt != A->cnt) ans += t->cnt;
		else break;
	}
}

int main() {

	while (scanf("%d", &n) != EOF) {

		TRIE* root = new TRIE;
		ans = 0;

		char str[100];
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			TRIE* t = root;
			for (int j = 0; str[j]; j++) {
				if (t->child[str[j] - 'a'] == NULL) {
					t->child[str[j] - 'a'] = new TRIE;
				}
				t = t->child[str[j] - 'a'];
				t->cnt++;
			}
		}

		dfs(root);
		printf("%.2lf\n", (double)ans / n);
		delete(root);
	}

	return 0;
}