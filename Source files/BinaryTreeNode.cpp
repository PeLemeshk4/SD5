#include "../Header files/BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int data) 
{
	_data = data;
	_left = nullptr;
	_right = nullptr;
}

BinaryTreeNode::~BinaryTreeNode() 
{
	_left = nullptr;
	_right = nullptr;
}

int BinaryTreeNode::GetData()
{
	return _data;
}

void BinaryTreeNode::SetData(int data)
{
	_data = data;
}

BinaryTreeNode* BinaryTreeNode::GetLeft()
{
	return _left;
}

void BinaryTreeNode::SetLeft(BinaryTreeNode* node)
{
	_left = node;
}

BinaryTreeNode* BinaryTreeNode::GetRight()
{
	return _right;
}

void BinaryTreeNode::SetRight(BinaryTreeNode* node)
{
	_right = node;
}

