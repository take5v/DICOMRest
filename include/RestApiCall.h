#ifndef RESTAPICALL_H
#define RESTAPICALL_H

#include <boost/noncopyable.hpp>

#include "RestApiOutput.h"

class RestApi;

class RestApiCall: public boost::noncopyable
{
private:
    RestApiOutput& output_;
    RestApi& context_;
public:
    RestApiCall(RestApiOutput& output, RestApi& context);
    RestApiCall();
    virtual ~RestApiCall();

    RestApiOutput& GetOutput();
    RestApi& GetContext();
protected:
private:
};

#endif // RESTAPICALL_H
