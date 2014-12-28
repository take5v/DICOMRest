#ifndef DICOMINSTANCETOSTORE_H
#define DICOMINSTANCETOSTORE_H

#include <string>

class DicomInstanceToStore
{
    std::string PatientName;
    std::string StudyID;
    std::string SeriesID;
public:
    DicomInstanceToStore();
    virtual ~DicomInstanceToStore();

    void SetBuffer(const std::string& buffer);

    std::string GetPatientName();
    std::string GetStudyID();
    std::string GetSeriesID();
protected:
private:
};

#endif // DICOMINSTANCETOSTORE_H
