/**
 * 1. 所有指针为空或不为空的判断，全部写成if(!p)或if(p)的形式，不和nullptr做比较
 * 2. nullptr是为了完美转发和重载匹配用的
 */

#include "binaryTree.h"


template<typename T>
binaryTree<T>::binaryTree()
{
    root_ = nullptr;
}

template<typename T>
binaryTree<T>::binaryTree(std::initializer_list<T> il)
    : binaryTree()
{
    for (const T& item : il)
    {
        /*pNode newNode = new node<T>(item);
        treeInsert(newNode);*/
        insert(item);
    }
}

template<typename T>
binaryTree<T>::binaryTree(std::vector<T>& v)
    : binaryTree()
{
    for (const T& item : v)
    {
        //std::cout << item << std::endl;
        /*pNode newNode = new node<T>(item);
        treeInsert(newNode);*/
        insert(item);
    }
}

template<typename T>
binaryTree<T>::~binaryTree()
{
    treeFree(root_);
}

template<typename T>
void binaryTree<T>::preOrderTreeWalk(pNode x)
{
    /*前序遍历*/
    if (x)
    {
        std::cout << x->key() << " ";
        preOrderTreeWalk(x->left());
        preOrderTreeWalk(x->right());
    }
}

template<typename T>
void binaryTree<T>::inOrderTreeWalk(pNode x)
{
    /*中序遍历*/
    if (x)
    {
        inOrderTreeWalk(x->left());
        std::cout << x->key() << " ";
        inOrderTreeWalk(x->right());
    }
}

template<typename T>
void binaryTree<T>::postOrderTreeWalk(pNode x)
{
    /*后序遍历*/
    if (x)
    {
        postOrderTreeWalk(x->left());
        postOrderTreeWalk(x->right());
        std::cout << x->key() << " ";
    }
}

template<typename T>
void binaryTree<T>::print()
{
    inOrderTreeWalk(root_);
    std::cout << std::endl;
}

/**
 * 1. 类模板的成员函数的返回值是类型别名时，需要使用typename class<T>::alias这种形式
 * 2. 涉及到一个在 template（模板）中的 nested dependent type name（嵌套依赖类型名）
 *    的任何时候，你必须把单词 typename 放在紧挨着它的前面
 * 3. 这样才能告诉编译器把它当作一个类型来处理，否则会被当成是别的标识符
 */
template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSearch(pNode x, T key)
{
    /*查找，用递归*/
    if (!x || key == x->key())
    {
        return x;
    }
    if (key < x->key())
    {
        return treeSearch(x->left(), key);
    }
    else
    {
        return treeSearch(x->right(), key);
    }
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::iterativeTreeSearch(pNode x, T key)
{
    /*查找，用循环代替递归，效率高*/
    while (x && key != x->key())
    {
        if (key < x->key())
        {
            x = x->left();
        }
        else
        {
            x = x->right();
        }
    }
    return x;
}

template<typename T>
T binaryTree<T>::search(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMinimum(pNode x)
{
    /*遍历到最左边的一个点*/
    while (x->left())
    {
        x = x->left();
    }
    return x;
}

template<typename T>
T binaryTree<T>::min()
{
    pNode res = treeMinimum(root_);
    return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMaximum(pNode x)
{
    /*遍历到最右边的一个点*/
    while (x->right())
    {
        x = x->right();
    }
    return x;
}

template<typename T>
T binaryTree<T>::max()
{
    pNode res = treeMaximum(root_);
    return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSuccessor(pNode x)
{
    /*当前节点有右子节点，沿着右边找后继*/
    if (x->right())
    {
        return treeMinimum(x->right());
    }
    /*当前节点没有右子节点，沿着父节点的右边向上找后继*/
    pNode y = x->parent();
    while (y && x == y->right())
    {
        x = y;
        y = y->parent();
    }
    return y;
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treePreSuccessor(pNode x)
{
    /*当前节点有左子节点，沿着左边找前驱*/
    if (x->left())
    {
        return treeMaximum(x->left());
    }
    pNode y = x->parent();
    while (y && x == y->left())
    {
        x = y;
        y = y->parent();
    }
    return y;
}

template<typename T>
T binaryTree<T>::successor(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    pNode suc = treeSuccessor(res);
    return suc->key();
}

template<typename T>
T binaryTree<T>::preSuccessor(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    pNode suc = treePreSuccessor(res);
    return suc->key();
}

template<typename T>
void binaryTree<T>::treeInsert(pNode z)
{
    pNode y = nullptr;
    pNode x = root_;
    while (x)
    {
        y = x;
        if (z->key() < x->key())
        {
            x = x->left();
        }
        else
        {
            x = x->right();
        }
    }
    z->setParent(y);
    if (!y)
    {
        /*树为空*/
        root_ = z;
    }
    else if (z->key() < y->key())
    {
        y->setLeft(z);
    }
    else
    {
        y->setRight(z);
    }
}

template<typename T>
void binaryTree<T>::transplant(pNode u, pNode v)
{
    if (!(u->parent()))
    {
        root_ = u;
    }
    else if (u == u->parent()->left())
    {
        u->parent()->setLeft(v);
    }
    else
    {
        u->parent()->setRight(v);
    }
    if (v != nullptr)
    {
        v->setParent(u->parent());
    }
}

template<typename T>
void binaryTree<T>::treeDelete(pNode z)
{
    if (!(z->left()))
    {
        transplant(z, z->right());
    }
    else if (!(z->right()))
    {
        transplant(z, z->left());
    }
    else
    {
        /*用y换z*/
        pNode y = treeMinimum(z);
        if (y->parent() != z)
        {
            transplant(y, y->right());
            y->setRight(z->right());
            y->right()->setParent(y);
        }
        transplant(z, y);
        y->setLeft(z->left());
        y->left()->setParent(y);
    }
    delete z;
}

template<typename T>
void binaryTree<T>::insert(T key)
{
    pNode newNode = new node<T>(key);
    treeInsert(newNode);
}

template<typename T>
void binaryTree<T>::remove(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    treeDelete(res);
}

template<typename T>
void binaryTree<T>::treeFree(pNode x)
{
    if (x)
    {
        treeFree(x->left());
        treeFree(x->right());
        delete x;
        x = nullptr;
        return;
    }
}

template class binaryTree<int>;
template class binaryTree<std::string>;
template class binaryTree<std::shared_ptr<std::string>>;