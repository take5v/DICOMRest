#ifndef RESTAPIDELETECALL_H
#define RESTAPIDELETECALL_H

#include "RestApiCall.h"

class RestApiDeleteCall : public RestApiCall
{
public:
    typedef void (*Handler) (RestApiDeleteCall& call);

    RestApiDeleteCall(RestApiOutput& output, RestApi& context);
    virtual ~RestApiDeleteCall();
protected:
private:
};

#endif // RESTAPIDELETECALL_H
