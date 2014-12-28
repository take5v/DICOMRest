#ifndef FROMDCMTKBRIDGE_H
#define FROMDCMTKBRIDGE_H

#include <dcmtk/dcmdata/dcdatset.h>

#include "Enumerations.h"

class FromDcmtkBridge
{
public:
    static Encoding DetectEncoding(DcmDataset& dataset);

    static void Convert(DicomMap& target, DcmDataset& dataset);

    static DicomTag Convert(const DcmTag& tag);

    static DicomTag GetTag(const DcmElement& element);

    static bool IsPrivateTag(DcmTag& tag);

    static bool IsPrivateTag(const DicomTag& tag);

    static DicomValue* ConvertLeafElement(DcmElement& element,
                                          Encoding encoding);

    static void ToJson(Json::Value& target,
                       DcmDataset& dataset,
                       unsigned int maxStringLength = 256);

    static void ToJson(Json::Value& target,
                       const std::string& path,
                       unsigned int maxStringLength = 256);

    static std::string GetName(const DicomTag& tag);

    static DicomTag ParseTag(const char* name);

    static DicomTag ParseTag(const std::string& name)
    {
        return ParseTag(name.c_str());
    }

    static bool HasTag(const DicomMap& fields,
                       const std::string& tagName)
    {
        return fields.HasTag(ParseTag(tagName));
    }

    static const DicomValue& GetValue(const DicomMap& fields,
                                      const std::string& tagName)
    {
        return fields.GetValue(ParseTag(tagName));
    }

    static void SetValue(DicomMap& target,
                         const std::string& tagName,
                         DicomValue* value)
    {
        target.SetValue(ParseTag(tagName), value);
    }

    static void Print(FILE* fp,
                      const DicomMap& m);

    static void ToJson(Json::Value& result,
                       const DicomMap& values);

    static std::string GenerateUniqueIdentifier(ResourceType level);

    static bool SaveToMemoryBuffer(std::string& buffer,
                                   DcmDataset& dataSet);
};

#endif // FROMDCMTKBRIDGE_H
