#include "ServerIndex.h"

#include <boost/thread/mutex.hpp>

#include "Enumerations.h"
#include "InstanceNode.h"
#include "ServerTools.h"

ServerIndex::ServerIndex()
{
    //ctor
}

ServerIndex::~ServerIndex()
{
    for(ServerIndexNodesType::iterator it = ServerIndexNodes.begin();
        it != ServerIndexNodes.end(); ++it)
    {
        delete it->second;
    }
}
StoreStatus ServerIndex::AddInstance(std::string publicID, std::string patientName,
                            std::string studyID, std::string seriesID)
{
    boost::mutex::scoped_lock lock(mutex_);
    std::string privateID = GenerateUUID();
    InstanceNode* node = new InstanceNode(privateID, publicID, patientName, studyID, seriesID);
    ServerIndexNodes[publicID] = node;

    return StoreStatus_Success;
}

void ServerIndex::GetAllInstanceUuids(Json::Value& target)
{
    boost::mutex::scoped_lock lock(mutex_);
    for(ServerIndexNodesType::iterator it = ServerIndexNodes.begin();
        it != ServerIndexNodes.end(); ++it)
    {
        target.append(it->second->GetPublicID());
    }
}

void ServerIndex::GetInstance(std::string id, Json::Value& target)
{
    boost::mutex::scoped_lock lock(mutex_);

    ServerIndexNodesType::iterator it = ServerIndexNodes.find(id);
    if (it != ServerIndexNodes.end())
    {
        target["ID"] = it->second->GetPublicID();
        target["PatientName"] = it->second->GetPatientName();
    }
    else
    {
        target["Error"] = "Item " + id + " not found";
    }
}

void ServerIndex::ModifyInstance(std::string id, Json::Value& from, Json::Value& target)
{
    boost::mutex::scoped_lock lock(mutex_);
    ServerIndexNodesType::iterator it = ServerIndexNodes.find(id);
    if (it != ServerIndexNodes.end())
    {
        if (from["Replace"].begin().key() == "PatientName")
        {
            it->second->SetPatientName(from["Replace"]["PatientName"].asString());
            target["ID"] = id;
        }
        else
        {
            target["Result"] = "Wrong replacing request";
        }
    }
    else
    {
        target["Result"] = "Instance ID not found";
    }
}
