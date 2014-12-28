#include "RestApi.h"

#include <boost/regex.hpp>

#include <sstream>
#include <string>

RestApi::RestApi()
{
    //ctor
}

RestApi::~RestApi()
{
    //dtor
}

void RestApi::Register(const std::string& path, RestApiGetCall::Handler handler)
{
    GetHandlers[path] = handler;
}

void RestApi::Register(const std::string& path, RestApiPostCall::Handler handler)
{
    PostHandlers[path] = handler;
}

void RestApi::Register(const std::string& path, RestApiDeleteCall::Handler handler)
{
    DeleteHandlers[path] = handler;
}

void RestApi::Handle(HttpOutput& httpOutput, const std::string& uri, const std::string& method, const std::string& body)
{
    if (method == "GET")
    {
        bool foundHandler = false;
        for (GetHandlersType::iterator it = GetHandlers.begin(); it != GetHandlers.end(); ++it)
        {
            boost::regex ex(it->first);
            if (boost::regex_match(uri, ex))
            {
                RestApiOutput restApiOutput(httpOutput);
                RestApiGetCall restApiGetCall(restApiOutput, *this);

                const int subs[] = {1};  // we just want to see group 1
                boost::sregex_token_iterator i(uri.begin(), uri.end(), ex, subs);
                std::string id = *i;

                restApiGetCall.SetResourceID(id);

                it->second(restApiGetCall);
                foundHandler = true;
                break;
            }
        }
        if (!foundHandler)
        {
            httpOutput.SendBody("Handler not found\n");
            return;
        }
    }
    else if (method == "POST")
    {
        bool foundHandler = false;
        for (PostHandlersType::iterator it = PostHandlers.begin(); it != PostHandlers.end(); ++it)
        {
            boost::regex ex(it->first);
            if (boost::regex_match(uri, ex))
            {
                RestApiOutput restApiOutput(httpOutput);
                RestApiPostCall restApiPostCall(restApiOutput, *this, body);

                const int subs[] = {1};  // we just want to see group 1
                boost::regex ex2(it->first);
                boost::sregex_token_iterator i(uri.begin(), uri.end(), ex2, subs);
                std::string id = *i;

                restApiPostCall.SetResourceID(id);

                it->second(restApiPostCall);
                foundHandler = true;
                break;
            }
        }
        if (!foundHandler)
        {
            httpOutput.SendBody("Handler not found");
            return;
        }
    }
    else
    {
        httpOutput.SendBody("Not implemented");
        return;
    }
}
