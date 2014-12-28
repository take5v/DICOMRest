#ifndef INSTANCENODE_H
#define INSTANCENODE_H

#include <string>

class InstanceNode
{
private:
    std::string privateID_;
    std::string publicID_;
    std::string patientName_;
    std::string studyID_;
    std::string seriesID_;

public:
    InstanceNode(std::string privateID, std::string publicID,
                 std::string patientName, std::string studyID,
                 std::string seriesID);
    virtual ~InstanceNode();

    std::string GetPublicID();
    std::string GetPatientName() { return patientName_; }
    void SetPatientName(std::string name) { patientName_ = name; }
protected:
private:
};

#endif // INSTANCENODE_H
