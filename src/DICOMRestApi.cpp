#include "DICOMRestApi.h"

#include <jsoncpp/json/json.h>

#include "ServerContext.h"

static void ListInstances(RestApiGetCall& call)
{
    Json::Value json;
    ServerContext& context = DICOMRestApi::GetContext(call);
    context.GetIndex().GetAllInstanceUuids(json);
    Json::Value id;
    call.GetOutput().AnswerJson(json);
}

static void ListInstance(RestApiGetCall& call)
{
    Json::Value json;
    ServerContext& context = DICOMRestApi::GetContext(call);
    context.GetIndex().GetInstance(call.GetResourceID(), json);
    call.GetOutput().AnswerJson(json);
}

static void ModifyInstance(RestApiPostCall& call)
{
    ServerContext& context = DICOMRestApi::GetContext(call);

    const std::string& postData = call.GetPostBody();
    if (postData.size() == 0)
    {
        return;
    }
    Json::Value json;
    Json::Value root;
    Json::Reader reader;
    if (reader.parse( postData, root ))
    {
        context.GetIndex().ModifyInstance(call.GetResourceID(), root, json);
    }
    else
    {
        json["Result"] = "Json was not parsed";
    }
    call.GetOutput().AnswerJson(json);
}

static void UploadDicomFile(RestApiPostCall& call)
{
    ServerContext& context = DICOMRestApi::GetContext(call);

    const std::string& postData = call.GetPostBody();
    if (postData.size() == 0)
    {
      return;
    }

    std::string publicId;
    StoreStatus status = context.Store(publicId, postData);

    Json::Value result = Json::objectValue;

    result["ID"] = publicId;
    result["Path"] = "/instances/" + publicId;
    result["Status"] = status;
    call.GetOutput().AnswerJson(result);
}


void DICOMRestApi::AnswerStoredInstance(RestApiPostCall& call,
        const std::string& publicId,
        StoreStatus status) const
{
    Json::Value result = Json::objectValue;

    if (status != StoreStatus_Failure)
    {
        result["ID"] = publicId;
        result["Path"] = "/instances" + publicId;
    }

    call.GetOutput().AnswerJson(result);
}

DICOMRestApi::DICOMRestApi(ServerContext& serverContext):
    serverContext_(serverContext)
{
    Register("/instances", ListInstances);
    Register("/instances/([a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12})/", ListInstance);
    Register("/instances", UploadDicomFile);
    Register("/instances/([a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12})/modify", ModifyInstance);
}

DICOMRestApi::~DICOMRestApi()
{
    //dtor
}
