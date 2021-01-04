#ifndef SALUT_TREE_BIN_NODE_H_
#define SALUT_TREE_BIN_NODE_H_

namespace salut {
namespace tree {

    // 节点颜色
    enum RBColor { RB_RED, RB_BALCK };

    template<class T>
    struct BinNode {
        T val;
        BinNode<T>* parent;
        BinNode<T>* lChild;
        BinNode<T>* rChild;
        RBColor color;

        BinNode() : parent(nullptr), lChild(nullptr), rChild(nullptr), color(RB_RED) {}
        BinNode(T v, BinNode<T>* p = nullptr, BinNode<T>* lc = nullptr, BinNode<T>* rc = nullptr, RBColor c = RB_RED) {}

        // 释放子节点
        void RelaseChilds()
        {
            if (lChild != nullptr) {
                lChild->RelaseChilds();
                delete lChild;
                lChild = nullptr;
            }
            if (rChild != nullptr) {
                rChild->RelaseChilds();
                delete rChild;
                rChild = nullptr;
            }
        }

        // 作为当前节点的左子节点插入新节点
        BinNode<T>* InsertAsLChild(const T& v)
        {
            if (lChild != nullptr) {
                return nullptr;
            }
            lChild = new BinNode<T>(v, this);
            return lChild;
        }

        // 作为当前节点的右子节点插入新节点
        BinNode<T>* InsertAsRChild(const T& v)
        {
            if (rChild != nullptr) {
                return nullptr;
            }
            rChild = new BinNode<T>(v, this);
            return rChild;
        }

        bool operator<(const BinNode<T> node) const { return val < node.val; }
        bool operator==(const BinNode<T> node) const { return val == node.val; }
    };

    template<class T>
    bool IsRoot(const BinNode<T>& node)
    {
        return node.parent == nullptr;
    }

    template<class T>
    bool HasRoot(const BinNode<T>& node)
    {
        return !IsRoot(node);
    }

    template<class T>
    bool IsLChild(const BinNode<T>& node)
    {
        return !IsRoot(node) && (&node == node.parent->lChild);
    }

    template<class T>
    bool IsRChild(const BinNode<T>& node)
    {
        return !IsRoot(node) && (&node == node.parent->rChild);
    }

    template<class T>
    bool HasLChild(const BinNode<T>& node)
    {
        return node.lChild != nullptr;
    }

    template<class T>
    bool HasRChild(const BinNode<T>& node)
    {
        return node.rChild != nullptr;
    }

    template<class T>
    bool HasChild(const BinNode<T>& node)
    {
        return HasLChild(node) || HasRChild(node);
    }

    template<class T>
    bool HasChilds(const BinNode<T>& node)
    {
        return HasLChild(node) && HasRChild(node);
    }

    template<class T>
    bool IsLeaf(const BinNode<T>& node)
    {
        return !HasChild(node);
    }
}  // namespace tree
}  // namespace salut

#endif  // SALUT_TREE_BIN_NODE_H_