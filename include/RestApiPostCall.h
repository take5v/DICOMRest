#ifndef RESTAPIPOSTCALL_H
#define RESTAPIPOSTCALL_H

#include "RestApiCall.h"

class RestApiPostCall : public RestApiCall
{
private:
    const std::string& data_;
    std::string ResourceID;

public:
    typedef void (*Handler) (RestApiPostCall& call);

    RestApiPostCall(RestApiOutput& output, RestApi& context, const std::string& data):
        RestApiCall(output, context),
        data_(data)
    {
    }
    virtual ~RestApiPostCall()
    {
    }

    const std::string& GetPostBody() const
    {
        return data_;
    }

    void SetResourceID(std::string resID) { ResourceID = resID; }
    std::string GetResourceID() { return ResourceID;}
protected:
private:
};

#endif // RESTAPIPOSTCALL_H
