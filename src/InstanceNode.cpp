#include "InstanceNode.h"

#include "ServerTools.h"

InstanceNode::InstanceNode(std::string privateID, std::string publicID,
             std::string patientName, std::string studyID,
             std::string seriesID):
             publicID_(publicID),
             patientName_(patientName),
             studyID_(studyID),
             seriesID_(seriesID),
             privateID_(privateID)
{
}

InstanceNode::~InstanceNode()
{
    //dtor
}

std::string InstanceNode::GetPublicID()
{
    return publicID_;
}
