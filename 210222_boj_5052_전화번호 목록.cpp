#include <iostream>

class TRIE {
public:
	TRIE* child[11]; // 0~9
	bool is_terminal;
	TRIE() {
		is_terminal = false;
		for (int i = 0; i < 10; ++i) child[i] = nullptr;
	}

	~TRIE() {
		for (int i = 0; i < 10; ++i) {
			if (child[i] != nullptr)
				delete(child[i]);
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int idx = *key - '0';
			if (child[idx] == nullptr) {
				child[idx] = new TRIE();
			}
			child[idx]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0') return false;
		if (is_terminal) return true;

		int idx = *key - '0';
		if (child[idx] == nullptr) {
			return false;
		}
		return child[idx]->find(key + 1);
	}
};

int t, n;
int main() {
	scanf("%d", &t);
	char call[10005][12];
	while (t--) {
		scanf("%d", &n);

		bool flg = false;
		TRIE* root = new TRIE();
		for (int i = 0; i < n; i++) {
			scanf("%s", &call[i]);
			root->insert(call[i]);
		}
		for (int i = 0; i < n; i++) {
			if (root->find(call[i])) {
				flg = true;
				break;
			}
		}
		if (flg) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
		delete root;
	}

	return 0; 
}