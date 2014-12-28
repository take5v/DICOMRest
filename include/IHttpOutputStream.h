#ifndef IHTTPOUTPUTSTREAM_H_INCLUDED
#define IHTTPOUTPUTSTREAM_H_INCLUDED

#include <boost/noncopyable.hpp>

#include <string>

class IHttpOutputStream: public boost::noncopyable
{
public:
    virtual ~IHttpOutputStream() {}

    virtual void Write(const char* buf, size_t size) = 0;
    virtual void SetHeader(const std::string& name, const std::string& value) = 0;
    virtual void SetContentType(const std::string& type) = 0;
};

#endif // IHTTPOUTPUTSTREAM_H_INCLUDED
