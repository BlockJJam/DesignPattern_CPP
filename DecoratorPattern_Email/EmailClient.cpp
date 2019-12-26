#include "EmailContent.h"

using namespace std;

void main()
{
	EmailContent * email = new BasicEmailContent("hello");
	cout << email->getContent() << endl;

	EmailContent * emailWithExternal = new ExternalDecorator(new BasicEmailContent("hello"));
	cout << emailWithExternal->getContent() << endl;

	EmailContent * emailWithExternalSecure = new SecureDecorator(new ExternalDecorator(new BasicEmailContent("hello ")));
	cout << emailWithExternalSecure->getContent() << endl;

}