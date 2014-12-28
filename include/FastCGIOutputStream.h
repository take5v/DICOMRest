#ifndef FASTCGIOUTPUTSTREAM_H
#define FASTCGIOUTPUTSTREAM_H

#include "IHttpOutputStream.h"

class FastCGIOutputStream: public IHttpOutputStream
{
private:
    fastcgi::Request* Request;

public:
    FastCGIOutputStream(fastcgi::Request* request);
    virtual ~FastCGIOutputStream();

    virtual void Write(const char* buf, size_t size);
    virtual void SetHeader(const std::string& name, const std::string& value);
    virtual void SetContentType(const std::string& type);
};

#endif // FASTCGIOUTPUTSTREAM_H
