#include "ServerContext.h"

#include "DicomInstanceToStore.h"

ServerContext::ServerContext(FileStorage& fileStorage, ServerIndex& serverIndex):
    fileStorage_(fileStorage),
    serverIndex_(serverIndex)
{
    //ctor
}

ServerContext::~ServerContext()
{
    //dtor
}

FileStorage& ServerContext::GetFileStorage()
{
    return fileStorage_;
}

StoreStatus ServerContext::Store(std::string& publicId, const std::string& data)
{
    DicomInstanceToStore toStore;
    toStore.SetBuffer(data);

    publicId = fileStorage_.AddFile(data.c_str(), data.size());
    StoreStatus status = serverIndex_.AddInstance(publicId, toStore.GetPatientName(), toStore.GetStudyID(), toStore.GetSeriesID());

    return status;
}
