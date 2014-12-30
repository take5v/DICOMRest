#include "DicomInstanceToStore.h"

#include "ServerTools.h"

DicomInstanceToStore::DicomInstanceToStore()
{
    //ctor
}

DicomInstanceToStore::~DicomInstanceToStore()
{
    //dtor
}

void DicomInstanceToStore::SetBuffer(const std::string& buffer)
{
    // fake file parsing
}
std::string DicomInstanceToStore::GetPatientName()
{
    return "ABCName";
}
std::string DicomInstanceToStore::GetStudyID()
{
    return GenerateUUID();
}
std::string DicomInstanceToStore::GetSeriesID()
{
    return GenerateUUID();
}
