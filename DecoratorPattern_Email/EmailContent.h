#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class EmailContent
{
public:
	virtual string getContent() = 0;
	virtual ~EmailContent() {}
};

class BasicEmailContent : public EmailContent
{
private:
	string _content;
public:
	BasicEmailContent(string content)
	{
		_content = content;
	}

	string getContent() override
	{
		return _content;
	}
};

class EmailDecorator : public EmailContent
{
private :
	EmailContent *_decoratedContent;

public:
	EmailDecorator(EmailContent *decoratedContent)
	{
		_decoratedContent = decoratedContent;
	}

	string getContent() override
	{
		return _decoratedContent->getContent();
	}
};

class ExternalDecorator : public EmailDecorator
{
private :
	EmailContent *_decoratedContent;
	string addDisclaimer(string &content)
	{
		return content + " Comapany Disclaimer ";
	}
public:
	ExternalDecorator(EmailContent *decoratedContent)
		: EmailDecorator(decoratedContent)
	{
		_decoratedContent = new EmailDecorator(decoratedContent);
	}

	string getContent() override
	{
		string content = _decoratedContent->getContent();
		string externalContent = addDisclaimer(content);
		return externalContent;
	}
};

class SecureDecorator : public EmailDecorator
{
private:
	EmailContent *_decoratedContent;
	
	string encrypt(string & content)
	{
		return content + " Encrypted";
	}
public:
	SecureDecorator(EmailContent *decoratedContent)
		: EmailDecorator(decoratedContent)
	{
		_decoratedContent = new EmailDecorator(decoratedContent);
	}

	string getContent() override
	{
		string content = _decoratedContent->getContent();
		string encryptedContent = encrypt(content);
		return encryptedContent;
	}
};