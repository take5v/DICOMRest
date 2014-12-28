#include <fastcgi2/request.h>

#include "FastCGIOutputStream.h"

FastCGIOutputStream::FastCGIOutputStream(fastcgi::Request* request):
    Request(request)
{
}
FastCGIOutputStream::~FastCGIOutputStream()
{
}
void FastCGIOutputStream::Write(const char* buf, size_t size)
{
    Request->write(buf, size);
}

void FastCGIOutputStream::SetHeader(const std::string& name, const std::string& value)
{
    Request->setHeader(name, value);
}

void FastCGIOutputStream::SetContentType(const std::string& type)
{
    Request->setContentType(type);
}
