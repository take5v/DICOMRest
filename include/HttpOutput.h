#ifndef HTTPOUTPUT_H
#define HTTPOUTPUT_H

#include <string>

#include "IHttpOutputStream.h"

class HttpOutput
{
private:
    IHttpOutputStream& Stream;
public:
    HttpOutput(IHttpOutputStream& stream);
    virtual ~HttpOutput();

    void SendStatus();
    void SetContextType();
    void SendBody(const char* buf, size_t size);
    void SendBody(const std::string& str);
    void SetHeader(const std::string& name, const std::string& value);
    void SetContentType(const std::string& type);
protected:
private:
};

#endif // HTTPOUTPUT_H
