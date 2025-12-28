#pragma once

//! \brief Структура узла декартового дерева.
struct TreapNode
{
	private:
		//! Ключ узла.
		int _key;

		//! Приоритет узла.
		int _priority;	

	public:
		//! Левый дочерний узел.
		TreapNode* _left;

		//! Правый дочерний узел.
		TreapNode* _right;

		//! \brief Удаляет узел в дерево.
		//! \param key Ключ узла.
		//! \param priority Приоритет узла.
		TreapNode(int key, int priority);

		//! \brief Освобождает память.
		~TreapNode();

		//! \brief Возвращает ключ узла.
		//! \return Ключ узла.
		int GetKey();

		//! \brief Возвращает приоритет узла.
		//! \return Приоритет узла.
		int GetPriority();

		//! \brief Возвращает левый дочерний узел.
		//! \return Левый дочерний узел.
		TreapNode* GetLeft();

		//! \brief Устанавливает левый дочерний узел.
		//! \param node Левый дочерний узел.
		void SetLeft(TreapNode* node);

		//! \brief Возвращает правый дочерний узел.
		//! \return Правый дочерний узел.
		TreapNode* GetRight();

		//! \brief Устанавливает правый дочерний узел.
		//! \param node Указатель на правый дочерний узел.
		void SetRight(TreapNode* node);
};
