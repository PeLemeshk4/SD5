#pragma once

//! \brief Структура узла бинарного дерева.
struct BinaryTreeNode 
{
	private:
		//! \brief Данные узла.
		int _data;

		//! \brief Левый дочерний узел.
		BinaryTreeNode* _left;

		//! \brief Правый дочерний узел.
		BinaryTreeNode* _right;

	public:
		//! \brief Создает узел бинарного дерева.
		//! \param data Значение узла.
		BinaryTreeNode(int data);

		//! \brief Освобождает память.
		~BinaryTreeNode();

		//! \brief Возвращает значение узла.
		//! \return Значение.
		int GetData();

		//! \brief Возвращает значение узла.
		void SetData(int data);

		//! \brief Возвращает указатель на левый дочерний узел.
		//! \return Указатель на левый дочерний узел.
		BinaryTreeNode* GetLeft();

		//! \brief Устанавливает левый дочерний узел.
		//! \param node Левый дочерний узел.
		void SetLeft(BinaryTreeNode* node);

		//! \brief Возвращает указатель на правый дочерний узел.
		//! \return Указатель на правый дочерний узел.
		BinaryTreeNode* GetRight();

		//! \brief Устанавливает правый дочерний узел.
		//! \param node Указатель на правый дочерний узел.
		void SetRight(BinaryTreeNode* node);
};
