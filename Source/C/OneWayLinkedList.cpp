#include "stdafx.h"
using namespace std;


struct Node
{
	int m_count;
	Node* m_next;

	Node(int c) :m_count(c), m_next(nullptr) {}
};


class MyLink
{
	Node* m_head;
	Node* m_tail;
public:

	MyLink() :m_head(nullptr), m_tail(nullptr) {}

	bool addNode(Node* node)
	{
		if (!node) return false;

		if (!m_head)
		{// ��ӵ�һ���ڵ�
			m_head = node;
			m_tail = m_head;
			m_tail->m_next = nullptr;
		}
		else
		{
			m_tail->m_next = node;
			m_tail->m_next->m_next = nullptr;
			m_tail = node; // �ǵõ���βָ��
		}
		return true;
	}
	void print()
	{
		Node* p = m_head;
		while (p)
		{
			printf("%d	", p->m_count);
			p = p->m_next;
		}
		printf("\n");
	}

	void reverseNode()
	{// ��ʹ��m_tail

	 // ����Ϊ�ջ���ֻ��һ���ڵ�
		if (!m_head || !m_head->m_next) return;

		Node* pre = nullptr;
		Node* p = m_head;
		Node* q = m_head->m_next;
		while (p->m_next)
		{
			p->m_next = pre;
			pre = p;
			p = q;
			q = p->m_next;
		}	
		p->m_next = pre;

		// Key������˼·�Ĺؼ���ÿһ���ڵ��nextָ��ǰһ���ڵ�
		// ����÷��ص�ͷָ��ָ��ԭʼ˳������һ���ڵ�
		// ԭʼ˳��1 -> 2 -> 3 -> 4��head -> 1
		// ����˼·��1 <- 2 <- 3 <- 4������� head ָ�� 4
		m_head = p;
	}

	~MyLink()
	{
		while (m_head)
		{// �ͷ����нڵ���ռ���ڴ�
			Node* p = m_head->m_next;
			delete[]m_head;
			m_head = p;
		}
	}
};

/////////////////////////////////////////////////////////////////
void oneWayLinkedList()
{
	MyLink link;
	for (int i = 0; i < 10; ++i)
	{
		// ������������ڴ棬������ʱ�����ͷź�ָ��ָ��ĵ�ַ���δ֪
		Node* node = new Node(i);
		link.addNode(node);
	}

	link.print();
	link.reverseNode();
	link.print();
}