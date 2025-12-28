#include "../Header files/BinaryTree.h"

BinaryTree::BinaryTree()
{
	_root = nullptr;
}

BinaryTree::~BinaryTree()
{
	if (_root)
	{
		delete _root;
	}
}

BinaryTreeNode* BinaryTree::GetRoot()
{
	return _root;
}

BinaryTreeNode* BinaryTree::AddElementRecursive(BinaryTreeNode* node, int data)
{
    if (!node)
    {
        return new BinaryTreeNode(data);
    }
    if (data < node->GetData())
    {
        node->SetLeft(AddElementRecursive(node->GetLeft(), data));
    }
    else if (data > node->GetData())
    {
        node->SetRight(AddElementRecursive(node->GetRight(), data));
    }
    return node;
}

void BinaryTree::AddElement(int data)
{
    _root = AddElementRecursive(_root, data);
}

BinaryTreeNode* BinaryTree::RemoveElementRecursive(BinaryTreeNode* node, int data)
{
    if (!node)
    {
        return nullptr;
    }
    if (data < node->GetData())
    {
        node->SetLeft(RemoveElementRecursive(node->GetLeft(), data));
    }
    else if (data > node->GetData())
    {
        node->SetRight(RemoveElementRecursive(node->GetRight(), data));
    }
    else
    {
        if (!node->GetLeft())
        {
            BinaryTreeNode* temp = node->GetRight();
            delete node;
            return temp;
        }
        else if (!node->GetRight())
        {
            BinaryTreeNode* temp = node->GetLeft();
            delete node;
            return temp;
        }
        BinaryTreeNode* temp = GetMinNodeRecursive(node->GetRight());
        node->SetData(temp->GetData());
        node->SetRight(RemoveElementRecursive(node->GetRight(), temp->GetData()));
    }
    return node;
}

void BinaryTree::RemoveElement(int data)
{
    _root = RemoveElementRecursive(_root, data);
}

BinaryTreeNode* BinaryTree::GetMinNodeRecursive(BinaryTreeNode* node)
{
    while (node && node->GetLeft())
    {
        node = node->GetLeft();
    }
    return node;
}

BinaryTreeNode* BinaryTree::GetMinNode()
{
    return GetMinNodeRecursive(_root);
}

BinaryTreeNode* BinaryTree::GetMaxNodeRecursive(BinaryTreeNode* node)
{
    while (node && node->GetRight())
    {
        node = node->GetRight();
    }
    return node;
}

BinaryTreeNode* BinaryTree::GetMaxNode()
{
    return GetMaxNodeRecursive(_root);
}

BinaryTreeNode* BinaryTree::SearchElementRecursive(BinaryTreeNode* node, int data)
{
    if (!node || node->GetData() == data)
    {
        return node;
    }
    if (data < node->GetData())
    {
        return SearchElementRecursive(node->GetLeft(), data);
    }
    return SearchElementRecursive(node->GetRight(), data);
}

BinaryTreeNode* BinaryTree::SearchElement(int data)
{
    return SearchElementRecursive(_root, data);
}

void BinaryTree::ClearRecursive(BinaryTreeNode* node)
{
    if (node)
    {
        ClearRecursive(node->GetLeft());
        ClearRecursive(node->GetRight());
        delete node;
    }
}

void BinaryTree::Clear()
{
    ClearRecursive(_root);
    _root = nullptr;
}
