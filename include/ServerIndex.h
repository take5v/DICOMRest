#ifndef SERVERINDEX_H
#define SERVERINDEX_H

#include <map>

#include <boost/thread.hpp>

#include <json/json.h>

#include "Enumerations.h"
#include "InstanceNode.h"

class ServerIndex
{
private:
    typedef std::map<std::string, InstanceNode*> ServerIndexNodesType;
    ServerIndexNodesType ServerIndexNodes;

    boost::mutex mutex_;
public:
    ServerIndex();
    virtual ~ServerIndex();

    StoreStatus AddInstance(std::string publicID, std::string patientName,
                   std::string studyID, std::string seriesID);
    void GetAllInstanceUuids(Json::Value& target);
    void GetInstance(std::string id, Json::Value& target);
    void ModifyInstance(std::string id, Json::Value& from, Json::Value& target);
protected:
private:
};

#endif // SERVERINDEX_H
