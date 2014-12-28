#ifndef RESTAPIGETCALL_H
#define RESTAPIGETCALL_H

#include <string>

#include "RestApiCall.h"

class RestApiGetCall : public RestApiCall
{
private:
    std::string ResourceID;

public:
    typedef void (*Handler) (RestApiGetCall& call);

    RestApiGetCall(RestApiOutput& output, RestApi& context);
    virtual ~RestApiGetCall();

    void SetResourceID(std::string resID) { ResourceID = resID; }
    std::string GetResourceID() { return ResourceID;}
protected:
private:
};

#endif // RESTAPIGETCALL_H
