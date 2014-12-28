#ifndef RESTAPIOUTPUT_H
#define RESTAPIOUTPUT_H

#include <jsoncpp/json/json.h>

#include "HttpOutput.h"

class RestApiOutput
{
private:
    HttpOutput& output_;
public:
    RestApiOutput(HttpOutput& output);
    virtual ~RestApiOutput();

    void AnswerJson(const Json::Value& value);
protected:
private:
};

#endif // RESTAPIOUTPUT_H
