#include "HttpOutput.h"

HttpOutput::HttpOutput(IHttpOutputStream& stream):
    Stream(stream)
{
}

HttpOutput::~HttpOutput()
{
    //dtor
}

void HttpOutput::SendBody(const char* buf, size_t size)
{
    Stream.Write(buf, size);
}

void HttpOutput::SendBody(const std::string& str)
{
    SendBody(str.c_str(), str.size());
}

void HttpOutput::SetHeader(const std::string& name, const std::string& value)
{
    Stream.SetHeader(name, value);
}

void HttpOutput::SetContentType(const std::string& type)
{
    Stream.SetContentType(type);
}
