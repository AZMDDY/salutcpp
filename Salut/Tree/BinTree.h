#ifndef SALUT_TREE_BIN_TREE_H_
#define SALUT_TREE_BIN_TREE_H_
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
                root = nullptr;
            }
        }

        bool Empty() { return root == nullptr; }

        

    private:
        BinNode<T>* root;
    };
}  // namespace tree
}  // namespace salut

#endif  // SALUT_TREE_BINARY_TREE_H_