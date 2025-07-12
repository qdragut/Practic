#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        }
        else {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    int calculateDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);

        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        }
        else {
            return rightDepth + 1;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    int getDepth() {
        return calculateDepth(root);
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    BinaryTree tree;
    char choice;
    int value;
    cout << "Добавьте узлы в дерево (для завершения введите 'n'):\n";
    while (true) {
        cout << "Введите число или 'n': ";
        cin >> choice;
        if (choice == 'n') break;
        cin.putback(choice);
        cin >> value;
        tree.insert(value);
    }

    cout << "Глубина дерева: " << tree.getDepth() << endl;
}