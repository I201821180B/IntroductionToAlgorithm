#include "rbTree.h"


template<typename T>
rbTree<T>::rbTree()
{
    nil_ = new node<T>(BLACK);
    nil_->setParent(nil_);
    nil_->setLeft(nil_);
    nil_->setRight(nil_);
    root_ = nil_;
}

template<typename T>
rbTree<T>::rbTree(std::initializer_list<T> il)
    : rbTree()
{
    for (const T& item : il)
    {
        insert(item);
    }
}

template<typename T>
rbTree<T>::rbTree(std::vector<T>& v)
    : rbTree()
{
    for (const T& item : v)
    {
        insert(item);
    }
}

template<typename T>
rbTree<T>::~rbTree()
{
    rbFree(root_);
    delete nil_;
}

template<typename T>
void rbTree<T>::preOrderTreeWalk(pNode x)
{
    /*前序遍历*/
    if (x != nil_)
    {
        std::cout << x->key() << " ";
        preOrderTreeWalk(x->left());
        preOrderTreeWalk(x->right());
    }
}

template<typename T>
void rbTree<T>::inOrderTreeWalk(pNode x)
{
    /*中序遍历*/
    if (x != nil_)
    {
        inOrderTreeWalk(x->left());
        std::cout << x->key() << " ";
        inOrderTreeWalk(x->right());
    }
}

template<typename T>
void rbTree<T>::postOrderTreeWalk(pNode x)
{
    /*后序遍历*/
    if (x != nil_)
    {
        postOrderTreeWalk(x->left());
        postOrderTreeWalk(x->right());
        std::cout << x->key() << " ";
    }
}

template<typename T>
void rbTree<T>::print()
{
    inOrderTreeWalk(root_);
    std::cout << std::endl;
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeSearch(pNode x, T key)
{
    /*查找，用递归*/
    if (x == nil_ || key == x->key())
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
typename rbTree<T>::pNode rbTree<T>::iterativeTreeSearch(pNode x, T key)
{
    /*查找，用循环代替递归，效率高*/
    while (x != nil_ && key != x->key())
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
T rbTree<T>::search(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    return res->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeMinimum(pNode x)
{
    /*遍历到最左边的一个点*/
    while (x->left() != nil_)
    {
        x = x->left();
    }
    return x;
}

template<typename T>
T rbTree<T>::min()
{
    pNode res = treeMinimum(root_);
    return res->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeMaximum(pNode x)
{
    /*遍历到最右边的一个点*/
    while (x->right() != nil_)
    {
        x = x->right();
    }
    return x;
}

template<typename T>
T rbTree<T>::max()
{
    pNode res = treeMaximum(root_);
    return res->key();
}

template<typename T>
T rbTree<T>::successor(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    pNode suc = rbSuccessor(res);
    return suc->key();
}

template<typename T>
T rbTree<T>::preSuccessor(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    pNode preSuc = rbPreSuccessor(res);
    return preSuc->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::rbSuccessor(pNode x)
{
    /*当前节点有右子节点，沿着右边找后继*/
    if (x->right() != nil_)
    {
        return treeMinimum(x->right());
    }
    /*当前节点没有右子节点，沿着父节点的右边向上找后继*/
    pNode y = x->parent();
    while (y != nil_ && x == y->right())
    {
        x = y;
        y = y->parent();
    }
    return y;
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::rbPreSuccessor(pNode x)
{
    /*当前节点有左子节点，沿着左边找前驱*/
    if (x->left() != nil_)
    {
        return treeMaximum(x->left());
    }
    pNode y = x->parent();
    while (y != nil_ && x == y->left())
    {
        x = y;
        y = y->parent();
    }
    return y;
}

template<typename T>
void rbTree<T>::rbInsert(pNode z)
{
    pNode y = nil_;
    pNode x = root_;
    while (x != nil_)
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
    // if no data in rbTree
    if (y == nil_)
    {
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
    //z->setParent(y);
    z->setLeft(nil_);
    z->setRight(nil_);
    z->setColor(RED);
    rbInsertFixup(z);
}

template<typename T>
void rbTree<T>::insert(T key)
{
    pNode newNode = new node<T>(key);
    rbInsert(newNode);
}

template<typename T>
void rbTree<T>::rbDelete(pNode z)
{
    pNode y = z;
    pNode x = nil_;
    COLOR yOriginColor = y->color();
    if (z->left() == nil_)
    {
        x = z->right();
        rbTransplant(z, z->right());
    }
    else if (z->right() == nil_)
    {
        x = z->left();
        rbTransplant(z, z->left());
    }
    else
    {
        y = treeMinimum(z->right());
        yOriginColor = y->color();
        x = y->right();
        if (y->parent() == z)
        {
            x->setParent(y);
        }
        else
        {
            rbTransplant(y, y->right());
            y->setRight(z->right());
            y->right()->setParent(y);
        }
        rbTransplant(z, y);
        y->setLeft(z->left());
        y->left()->setParent(y);
        y->setColor(z->color());
    }
    if (yOriginColor == BLACK)
    {
        rbDeleteFixup(x);
    }
    delete z;
}

template<typename T>
void rbTree<T>::remove(T key)
{
    pNode res = iterativeTreeSearch(root_, key);
    rbDelete(res);
}

template<typename T>
void rbTree<T>::leftRotate(pNode x)
{
    /*set right node of x*/
    pNode y = x->right();
    x->setRight(y->left());

    /*set parent of y's left node*/
    if (y->left() != nil_)
    {
        y->left()->setParent(x);
    }

    /*set parent node of y*/
    y->setParent(x->parent());

    /*set x's parent left or right node*/
    if (x->parent() == nil_)
    {
        root_ = y;
    }
    else if (x == x->parent()->left())
    {
        x->parent()->setLeft(y);
    }
    else
    {
        x->parent()->setRight(y);
    }

    y->setLeft(x);
    x->setParent(y);
}

template<typename T>
void rbTree<T>::rightRotate(pNode y)
{
    /*set left node of y*/
    pNode x = y->left();
    y->setLeft(x->right());

    /*set parent node of x's right node */
    if (x->right() != nil_)
    {
        x->right()->setParent(y);
    }

    /*set parent node of x*/
    x->setParent(y->parent());

    /*set y's parent left or right node*/
    if (y->parent() == nil_)
    {
        root_ = x;
    }
    else if (y == y->parent()->left())
    {
        y->parent()->setLeft(x);
    }
    else
    {
        y->parent()->setRight(x);
    }

    x->setRight(y);
    y->setParent(x);
}

template<typename T>
void rbTree<T>::rbInsertFixup(pNode z)
{
    while (z->parent()->color() == RED)
    {
        /*如果该节点在一个子树的左枝*/
        if (z->parent() == z->parent()->parent()->left())
        {
            /*取得叔节点*/
            pNode y = z->parent()->parent()->right();
            /*case 1: z和父节点都是红色，叔节点也是红色*/
            if (y->color() == RED)
            {
                z->parent()->setColor(BLACK);
                y->setColor(BLACK);
                z->parent()->parent()->setColor(RED);
                z = z->parent()->parent();
            }
            else
            {
                /*case 2：z和父节点都是红色，叔节点是黑色，z为右孩子*/
                if (z == z->parent()->right())
                {
                    z = z->parent();
                    leftRotate(z);
                }
                /*case 3：z和父节点都是红色，叔节点是黑色，z为左孩子*/
                z->parent()->setColor(BLACK);
                z->parent()->parent()->setColor(RED);
                rightRotate(z->parent()->parent());//
            }
        }
        /*如果该节点在一个子树的右枝*/
        else
        {
            pNode y = z->parent()->parent()->left();
            /*case 1*/
            if (y->color() == RED)
            {
                z->parent()->setColor(BLACK);
                y->setColor(BLACK);
                z->parent()->parent()->setColor(RED);
                z = z->parent()->parent();
            }
            
            else 
            {
                /*case 2*/
                if (z == z->parent()->left())
                {
                    z = z->parent();
                    rightRotate(z);
                }
                /*case 3*/
                z->parent()->setColor(BLACK);
                z->parent()->parent()->setColor(RED);
                leftRotate(z->parent()->parent());//
            }
        }
    }
    root_->setColor(BLACK);
}

template<typename T>
void rbTree<T>::rbTransplant(pNode u, pNode v)
{
    if (u->parent() == nil_)
    {
        root_ = v;
    }
    else if (u == u->parent()->left())
    {
        u->parent()->setLeft(v);
    }
    else
    {
        u->parent()->setRight(v);
    }
    v->setParent(u->parent());
}

template<typename T>
void rbTree<T>::rbDeleteFixup(pNode x)
{
    while (x != root_ && x->color() == BLACK)
    {
        if (x == x->parent()->left())
        {
            pNode w = x->parent()->right();
            if (w->color() == RED)
            {
                w->setColor(BLACK);
                x->parent()->setColor(RED);
                leftRotate(x->parent());
                w = x->parent()->right();
            }
            if (w->left()->color() == BLACK && w->right()->color() == BLACK)
            {
                w->setColor(RED);
                x = x->parent();
            }
            else if (w->right()->color() == BLACK)
            {
                w->left()->setColor(BLACK);
                w->setColor(RED);
                rightRotate(w);
                w = x->parent()->right();
            }
            w->setColor(x->parent()->color());
            x->parent()->setColor(BLACK);
            w->right()->setColor(BLACK);
            leftRotate(x->parent());
            x = root_;
        }
        else
        {
            pNode w = x->parent()->left();
            if (w->color() == RED)
            {
                w->setColor(BLACK);
                x->parent()->setColor(RED);
                rightRotate(x->parent());
                w = x->parent()->left();
            }
            if (w->right()->color() == BLACK && w->left()->color() == BLACK)
            {
                w->setColor(RED);
                x = x->parent();
            }
            else if (w->left()->color() == BLACK)
            {
                w->right()->setColor(BLACK);
                w->setColor(RED);
                leftRotate(w);
                w = x->parent()->left();
            }
            w->setColor(x->parent()->color());
            x->parent()->setColor(BLACK);
            w->left()->setColor(BLACK);
            rightRotate(x->parent());
            x = root_;
        }
    }
    x->setColor(BLACK);
}

template<typename T>
void rbTree<T>::rbFree(pNode x)
{
    if (x != nil_)
    {
        rbFree(x->left());
        rbFree(x->right());
        delete x;
        x = nullptr;
        return;
    }
}


template class rbTree<int>;
template class rbTree<std::string>;
template class rbTree<std::shared_ptr<std::string>>;