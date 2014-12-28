#include "RestApiOutput.h"

#include <jsoncpp/json/json.h>

#include "HttpOutput.h"

RestApiOutput::RestApiOutput(HttpOutput& output):
    output_(output)
{
    //ctor
}

RestApiOutput::~RestApiOutput()
{
    //dtor
}

void RestApiOutput::AnswerJson(const Json::Value& value)
{
    Json::StyledWriter writer;
    output_.SetContentType("application/json");
    output_.SendBody(writer.write(value));
}
