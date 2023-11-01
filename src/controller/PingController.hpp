#pragma once

#include "dto/StatusDto.hpp"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class PingController : public oatpp::web::server::api::ApiController {
public:
    PingController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
     : oatpp::web::server::api::ApiController(objectMapper)
    {}

public:
    static std::shared_ptr<PingController> createShared(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) {
        return std::make_shared<PingController>(objectMapper);
    }

    ENDPOINT_INFO(ping) {
        info->addTag("Status"); 
        info->summary = "Ping connection to API";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    }
    ENDPOINT("GET", "/api/ping", ping) {
        auto dto = StatusDto::createShared();
        dto->code = 200;
        dto->status = "OK";
        dto->message = "pong";
        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)
