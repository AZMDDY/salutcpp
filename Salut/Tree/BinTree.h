#ifndef SALUT_TREE_BIN_TREE_H_
#define SALUT_TREE_BIN_TREE_H_

#include <stack>
#include <queue>

#include "BinNode.h"

namespace salut {
namespace tree {
    template<class T>
    class BinTree {
    public:
        BinTree() : root(nullptr) {}

        ~BinTree()
        {
            if (root != nullptr) {
                root->RelaseChilds();
                delete root;
                root = nullptr;
            }
        }

        bool Empty() { return root == nullptr; }
        BinNode<T>* Root() const { return root; }

        BinNode<T>* InsertAsRoot(const T& v)
        {
            if (root != nullptr) {
                root->val = v;
            } else {
                root = new BinNode<T>(v);
            }
            return root;
        }

        BinNode<T>* InsertAsLC(BinNode<T>* node, const T& v)
        {
            if (node == nullptr) {
                return nullptr;
            }
            return node->InsertAsLChild(v);
        }

        BinNode<T>* InsertAsRC(BinNode<T>* node, const T& v)
        {
            if (node == nullptr) {
                return nullptr;
            }
            return node->InsertAsRChild(v);
        }

        BinNode<T>* AttachAsLC(BinNode<T>* node, BinTree<T>*& subTree)
        {
            if (node == nullptr || node->lChild != nullptr) {
                return nullptr;
            }
            if (subTree->root->parent != nullptr) {
                if (subTree->root->parent->lChild == subTree->root) {
                    subTree->root->parent->lChild = nullptr;
                }
                if (subTree->root->parent->rChild == subTree->root) {
                    subTree->root->parent->rChild = nullptr;
                }
            }
            node->lChild = subTree->root;
            node->lChild->parent = node;
            subTree->root = nullptr;
            subTree = nullptr;
            return node;
        }

        BinNode<T>* AttachAsRC(BinNode<T>* node, BinNode<T>*& subTree)
        {
            if (node == nullptr || node->rChild != nullptr) {
                return nullptr;
            }
            if (subTree->root->parent != nullptr) {
                if (subTree->root->parent->lChild == subTree->root) {
                    subTree->root->parent->lChild = nullptr;
                }
                if (subTree->root->parent->rChild == subTree->root) {
                    subTree->root->parent->rChild = nullptr;
                }
            }
            node->rChild = subTree->root;
            node->rChild->parent = node;
            subTree->root = nullptr;
            subTree = nullptr;
            return node;
        }

        BinTree<T>* Detach(BinNode<T>* node)
        {
            if (node == nullptr) {
                return nullptr;
            }
            if (node->parent != nullptr) {
                if (node->parent->lChild == node) {
                    node->parent->lChild = nullptr;
                }
                if (node->parent->rChild == node) {
                    node->parent->rChild = nullptr;
                }
                node->parent = nullptr;
            }
            BinTree<T>* tree = new BinTree<T>();
            tree->root = node;
            return tree;
        }

        std::vector<T> PreorderTraversal(BinNode<T>* node)
        {
            std::vector<T> ans;
            std::stack<BinNode<T>*> stk;
            while (node != nullptr) {
                while (node != nullptr) {
                    ans.push_back(node->val);
                    if (node->rChild != nullptr) {
                        stk.push(node->rChild);
                    }
                    node = node->lChild;
                }
                if (stk.empty()) {
                    break;
                }
                node = stk.top();
                stk.pop();
            }
            return ans;
        }

        std::vector<T> InorderTraversal(BinNode<T>* node)
        {
            std::vector<T> ans;
            std::stack<BinNode<T>*> stk;
            while (node != nullptr || !stk.empty()) {
                while (node != nullptr) {
                    stk.push(node);
                    node = node->lChild;
                }
                node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                node = node->rChild;
            }
            return ans;
        }

        std::vector<T> PostorderTraversal(BinNode<T>* node)
        {
            std::vector<T> ans;
            std::stack<BinNode<T>*> stk;
            if (node == nullptr) {
                return ans;
            }
            stk.push(node);
            while (!stk.empty()) {
                BinNode<T>* tmpNode = stk.top();
                stk.pop();
                ans.push_back(tmpNode->val);
                if (tmpNode->lChild != nullptr) {
                    stk.push(node->lChild);
                }
                if (tmpNode->rChild != nullptr) {
                    stk.push(node->rChild);
                }
            }
            std::reverse(ans.begin(), ans.end());
            return ans;
        }

        std::vector<T> LevelTraversal(BinNode<T>* node)
        {
            std::vector<T> ans;
            std::queue<BinNode<T>*> que;
            if (node == nullptr) {
                return ans;
            }
            que.push(node);
            while (!que.empty()) {
                BinNode<T>* tmpNode = que.front();
                que.pop();
                ans.push_back(tmpNode->val);
                if (tmpNode->lChild != nullptr) {
                    que.push(tmpNode->lChild);
                }
                if (tmpNode->rChild != nullptr) {
                    que.push(tmpNode->rChild);
                }
            }
            return ans;
        }

    private:
        BinNode<T>* root;
    };
}  // namespace tree
}  // namespace salut

#endif  // SALUT_TREE_BINARY_TREE_H_