#include <iostream>
using namespace std;

template < typename T>
class TemplateSingleton
{
protected:
	 TemplateSingleton()
	{}

	virtual ~TemplateSingleton()
	{}

public:
	static T * GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new T;
		return m_pInstance;
	};

	static void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	};

private:
	static T * m_pInstance;
};
template <typename T> T * TemplateSingleton<T>::m_pInstance = 0;

class CObject : public TemplateSingleton<CObject>
{
public:
	
};

int main()
{
	CObject *obj = new CObject();
	obj->GetInstance();
	
	CObject *obj2 = new CObject();
	obj2->GetInstance();

	return 0;
}