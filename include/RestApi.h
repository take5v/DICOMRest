#ifndef RESTAPI_H
#define RESTAPI_H

#include <utility>
#include <map>
#include <string>

#include "Enumerations.h"
#include "RestApiGetCall.h"
#include "RestApiPostCall.h"
#include "RestApiDeleteCall.h"

class RestApi
{
protected:
    typedef std::map<std::string, RestApiGetCall::Handler> GetHandlersType;
    typedef std::map<std::string, RestApiPostCall::Handler> PostHandlersType;
    typedef std::map<std::string, RestApiDeleteCall::Handler> DeleteHandlersType;
    GetHandlersType GetHandlers;
    PostHandlersType PostHandlers;
    DeleteHandlersType DeleteHandlers;

public:
    RestApi();
    virtual ~RestApi();

    void Register(const std::string& path, RestApiGetCall::Handler handler);

    void Register(const std::string& path, RestApiPostCall::Handler handler);

    void Register(const std::string& path, RestApiDeleteCall::Handler handler);

    void Handle(HttpOutput& httpOutput, const std::string& uri, const std::string& method, const std::string& body);
    //virtual void HandleInternal(HttpOutput& httpOutput, const std::string& uri, const std::string& method) = 0;

protected:
private:
};

#endif // RESTAPI_H
