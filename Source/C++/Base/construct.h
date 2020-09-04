#pragma once





// ����ƣ������͹��죬����private���ǲ��������͹���
#define COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&); \
	TypeName& operator=(const TypeName&)

// ����ƣ�������new��delete������private���ǲ��������ʵ����
#define OPERATOR_NEW_DELETE(TypeName) \
	void * operator new (size_t size); \
	void operator delete (void *ptr)


class SimpleObject
{
private:
	COPY_AND_ASSIGN(SimpleObject);
	OPERATOR_NEW_DELETE(SimpleObject);

public:
	SimpleObject() { m_i = 0; }
	~SimpleObject() {}

private:
	int m_i;
};