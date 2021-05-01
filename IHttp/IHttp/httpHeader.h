#pragma once
#include <string>
#include <map>
#include "IHttpInterface.h"


class CHttpHeader
{
public:
	CHttpHeader();
	CHttpHeader(const char* pHeader);
	CHttpHeader(const std::string& strHeader);
	CHttpHeader(CHttpHeader&& rhs);
	virtual	~CHttpHeader(void);


	const std::string& getHttpVersion()const { return http_version_; }
	void setHttpVersion(const std::string& version) { http_version_ = version; }
	void setRequestPath(const std::string& path) { request_page_ = path; }

	const int GetHttpCode()const { return http_code_; }

	const char*	GetContent()const { return http_response_.c_str(); }

	std::string	GetValue(const std::string& strKey);

	void addHeader(const std::string& key, const std::string& value);
	void setUserAgent(const std::string& userAgent);
	void setHost(const std::string& host);
	void setRange(__int64 range);

	//ת��http����ͷ
	std::string toString(HttpRequest type);
	//ת��http����ͷ�б�
	std::string toHttpHeaders();

protected:
	//����HTTPͷ�ṹ
	bool Revolse(const std::string& strHeader);

private:
	int	 http_code_;
	std::string http_version_;
	std::string	http_response_;
	std::string request_page_;
	std::map<std::string, std::string>	http_headers;
};