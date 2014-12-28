#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>
#include <fastcgi2/data_buffer.h>

#include <iostream>
#include <sstream>
#include <string>

#include "DICOMRestApi.h"
#include "IHttpOutputStream.h"
#include "HttpOutput.h"
#include "FastCGIOutputStream.h"
#include "ServerContext.h"
#include "FileStorage.h"
#include "ServerIndex.h"

class DICOMRestHandler : virtual public fastcgi::Component, virtual public fastcgi::Handler {

private:
    DICOMRestApi* restApi;
    FileStorage* fileStorage;
    ServerIndex* serverIndex;
    ServerContext* context;

public:
        DICOMRestHandler(fastcgi::ComponentContext *context) :
                fastcgi::Component(context) {
        }
        virtual ~DICOMRestHandler() {
        }

public:
        virtual void onLoad() {
            fileStorage = new FileStorage;
            serverIndex = new ServerIndex;
            context = new ServerContext(*fileStorage, *serverIndex);
            restApi = new DICOMRestApi(*context);
        }
        virtual void onUnload() {
            delete fileStorage;
            delete serverIndex;
            delete context;
            delete restApi;
        }
        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context) {
                //Здесь размещается код обработки запроса

                FastCGIOutputStream fastcgioutputstream(request);
                HttpOutput httpOutput(fastcgioutputstream);

                std::string uri = request->getURI();
                //request->write(uri.c_str(), uri.size());
                std::string method = request->getRequestMethod();

                fastcgi::DataBuffer bodyBuffer = request->requestBody();
                std::string body;
                bodyBuffer.toString(body);

                restApi->Handle(httpOutput, uri, method, body);

//                httpOutput.SetHeader("Simple-Header", "Reply from DICOMRest");
//                httpOutput.SetContentType("text/plain");
        }
};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("DICOMRestFactory", DICOMRestHandler)
FCGIDAEMON_REGISTER_FACTORIES_END()
