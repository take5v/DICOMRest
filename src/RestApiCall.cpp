#include "RestApiCall.h"

//#include "RestApi.h"

RestApiCall::RestApiCall(RestApiOutput& output, RestApi& context):
    output_(output),
    context_(context)
{
    //ctor
}

RestApiCall::~RestApiCall()
{
    //dtor
}

RestApiOutput& RestApiCall::GetOutput()
{
    return output_;
}

RestApi& RestApiCall::GetContext()
{
    return context_;
}
