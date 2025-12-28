#pragma once

#include "BinaryTreeNode.h"

//! \brief Структура бинарного дерева.
struct BinaryTree
{
	private:
		//! \brief Корень дерева.
		BinaryTreeNode* _root;

	public:
		//! \brief Создает бинарное дерево.
		BinaryTree();

		//! \brief Освобождает память.
		~BinaryTree();

		//! \brief Возвращает узел с минимальным значением.
		//! \return Указатель на узел с минимальным значением.
		BinaryTreeNode* GetRoot();

		//! \brief Добавляет узел в дерево.
		//! \param data Значение узла.
		void AddElement(int data);

		//! \brief Удаляет узел в дереве.
		//! \param data Значение узла.
		void RemoveElement(int data);

		//! \brief Возвращает указатель узел с минимальным значением.
		//! \return Указатель на узел с минимальным значением.
		BinaryTreeNode* GetMinNode();

		//! \brief Возвращает указатель узел с максимальным значением.
		//! \return Указатель на узел с максимальным значением.
		BinaryTreeNode* GetMaxNode();

		//! \brief Ищет узел по значению.
		//! \param data Значение узла.
		//! \return Указатель на узел или nullptr, если не удалось найти.
		BinaryTreeNode* SearchElement(int data);

		//! \brief Удаляет все узлы дерева.
		void Clear();

	private:
		BinaryTreeNode* AddElementRecursive(BinaryTreeNode* node, int data);
		BinaryTreeNode* RemoveElementRecursive(BinaryTreeNode* node, int data);
		BinaryTreeNode* GetMinNodeRecursive(BinaryTreeNode* node);
		BinaryTreeNode* GetMaxNodeRecursive(BinaryTreeNode* node);
		BinaryTreeNode* SearchElementRecursive(BinaryTreeNode* node, int data);
		void ClearRecursive(BinaryTreeNode* node);
};
