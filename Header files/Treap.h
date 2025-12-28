#pragma once

#include "TreapNode.h"

//! \brief Структура декартового дерево.
struct Treap
{
private:
	//! Корневой узел дерева.
	TreapNode* _root;

	//! Разделяет дерево на два поддерева.
	//! \param root Корень дерева или поддерева.
	//! \param key Ключ, по которому нужно разделить.
	//! \param left Левая часть поддерева.
	//! \param right Правая часть поддерева.
	void Split(TreapNode* root, int key, TreapNode*& left, TreapNode*& right);

	//! Объединение два поддререва.
	//! \param left Левая часть поддерева.
	//! \param right Правая часть поддерева.
	 //! \return Объеденненое дерево.
	TreapNode* Merge(TreapNode* left, TreapNode* right);

public:
	//! \brief Создает декартово дерево.
	Treap();

	//! \brief Освобождает память.
	~Treap();

	//! \brief Возвращает корень кучи.
	//! \return Корень кучи.
	TreapNode* GetRoot();

	//! \brief Присваивает корень.
	void SetRoot(TreapNode* root);

	//! Находит приоритет узла по ключу.
	//! \param key Ключ, по которому ищется значение приоритета.
	//! \return Приоритет дерева.
	int FindElement(int key);

	//! Добавляет элемент, используя неоптимизированный алгоритм (1 Split, 2 Merge).
	//! \param key Ключ узла.
	//! \param priority Приоритет узла.
    //! \return Указатель на добавленный узел дерева.
	TreapNode* InsertUnoptimized(int key, int priority);

	//! Добавляет элемент, используя оптимизированный алгоритм (1 Split).
	//! \param key Ключ узла.
	//! \param priority Приоритет узла.
	//! \return Указатель на добавленный узел дерева.
	TreapNode* InsertOptimized(TreapNode* node, int key, int priority);

	//! Удаляет элемент, используя неоптимизированный алгоритм (2 Split, 1 Merge).
	//! \param key Ключ узла.
    //! \return Указатель на удаленный узел дерева.
	TreapNode* RemoveUnoptimized(int key);

	//! Удаляет элемент, используя оптимизированный алгоритм (1 Merge).
	//! \param key Ключ узла.
	//! \return Указатель на удаленный узел дерева.
	TreapNode* RemoveOptimized(TreapNode* node, int key);

	//! \brief Удаляет все узлы кучи.
	void Clear(TreapNode* node);
};