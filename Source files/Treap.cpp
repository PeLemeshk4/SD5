#include "../Header files/Treap.h"

void Treap::Split(TreapNode* root, int key, TreapNode*& left, TreapNode*& right)
{
    if (!root)
    {
        left = nullptr;
        right = nullptr;
        return;
    }
    if (root->GetKey() <= key)
    {
        Split(root->GetRight(), key, root->_right, right);
        left = root;
    }
    else
    {
        Split(root->GetLeft(), key, left, root->_left);
        right = root;
    }
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
    if (!left) return right;
    if (!right) return left;

    if (left->GetPriority() <= right->GetPriority())
    {
        left->SetRight(Merge(left->GetRight(), right));

        return left;
    }
    else
    {
        right->SetLeft(Merge(left, right->GetLeft()));

        return right;
    }
}

Treap::Treap()
{
	_root = nullptr;
}

Treap::~Treap()
{
    Clear(_root);
}

TreapNode* Treap::GetRoot()
{
    return _root;
}

void Treap::SetRoot(TreapNode* root)
{
    _root = root;
}

int Treap::FindElement(int key)
{
    TreapNode* node = _root;
    while (node)
    {
        if (node->GetKey() == key) return node->GetPriority();
        if (key < node->GetKey())
        {
            node = node->GetLeft();
        }
        else
        {
            node = node->GetRight();
        }
    }
    return -1;
}

TreapNode* Treap::InsertUnoptimized(int key, int priority)
{   
    if (_root)
    {
        TreapNode* left = nullptr;
        TreapNode* right = nullptr;
        Split(_root, key, left, right);
        TreapNode* newNode = nullptr;
        if (right && (right->GetKey() == key && right->GetPriority() == priority))
        {
            return nullptr;
        }
        newNode = new TreapNode(key, priority);
        right = Merge(newNode, right);
        _root = Merge(left, right);

        return newNode;
    }
    else
    {
        _root = new TreapNode(key, priority);
        return _root;
    }   
}

TreapNode* Treap::InsertOptimized(TreapNode* node, int key, int priority)
{
    if (!node)
    {
        return new TreapNode(key, priority);
    }

    if (node->GetKey() == key && node->GetPriority() == priority)
    {
        return node;
    }

    if (priority < node->GetPriority())
    {
        TreapNode* left = nullptr;
        TreapNode* right = nullptr;
        Split(node, key, left, right);
        TreapNode* newNode = new TreapNode(key, priority);
        newNode->SetLeft(left);
        newNode->SetRight(right);
        return newNode;
    }
    else
    {
        if (key < node->GetKey())
        {
            node->SetLeft(InsertOptimized(node->GetLeft(), key, priority));
        }
        else
        {
            node->SetRight(InsertOptimized(node->GetRight(), key, priority));
        }
        return node;
    }
}

TreapNode* Treap::RemoveUnoptimized(int key)
{
    TreapNode* left1 = nullptr;
    TreapNode* mid = nullptr;
    TreapNode* right = nullptr;
    Split(_root, key, left1, right);

    TreapNode* left2 = nullptr;
    TreapNode* target = nullptr;
    Split(left1, key - 1, left2, target);

    if (target)
    {
        TreapNode* t = target;
        TreapNode* parent = nullptr;
        if (t->GetKey() == key)
        {
            target = Merge(t->GetLeft(), t->GetRight());
            delete t;
        }
    }

    _root = Merge(left2, Merge(target, right));
    return nullptr;
}

TreapNode* Treap::RemoveOptimized(TreapNode* node, int key)
{
    if (!node) return nullptr;

    if (node->GetKey() == key)
    {
        TreapNode* left = node->GetLeft();
        TreapNode* right = node->GetRight();
        delete node;
        return Merge(left, right);
    }
    else if (key < node->GetKey())
    {
        node->SetLeft(RemoveOptimized(node->GetLeft(), key));
    }
    else
    {
        node->SetRight(RemoveOptimized(node->GetRight(), key));
    }
    return node;
}

void Treap::Clear(TreapNode* node)
{
    if (!node) return;
    Clear(node->GetLeft());
    Clear(node->GetRight());
    delete node;
    _root = nullptr;
}