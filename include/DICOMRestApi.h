#ifndef DICOMRESTAPI_H_INCLUDED
#define DICOMRESTAPI_H_INCLUDED

#include "Enumerations.h"
#include "RestApi.h"
#include "ServerContext.h"
#include "RestApiCall.h"

class ServerContext;

class DICOMRestApi : public RestApi
{
private:
    ServerContext& serverContext_;

public:
    DICOMRestApi(ServerContext& serverContext);
    virtual ~DICOMRestApi();

    void AnswerStoredInstance(RestApiPostCall& call,
        const std::string& publicId,
        StoreStatus status) const;

    static DICOMRestApi& GetApi(RestApiCall& call)
    {
      return dynamic_cast<DICOMRestApi&>(call.GetContext());
    }
    static ServerContext& GetContext(RestApiCall& call)
    {
      return GetApi(call).serverContext_;
    }
};

#endif // DICOMRESTAPI_H_INCLUDED
