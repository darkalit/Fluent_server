#pragma once

#include "db/Database.hpp"
#include "dto/StatusDto.hpp"
#include "dto/UserDto.hpp"
#include "mongocxx/collection.hpp"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
private:
    OATPP_COMPONENT(std::shared_ptr<Database>, m_db);
public:
    UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
     : oatpp::web::server::api::ApiController(objectMapper)
    {}

public:
    static std::shared_ptr<UserController> createShared(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) {
        return std::make_shared<UserController>(objectMapper);
    }

    ENDPOINT_INFO(addUser) {
        info->addTag("User"); 
        // info->summary = "Ping connection to API";
        // info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    }
    ENDPOINT("GET", "/api/user", addUser) {
        auto dto = UserDto::createShared();
        dto->role = Role::USER;
        dto->email = "mail...";
        dto->password = "dfdf";
        dto->username = "user";

        // (*m_database)["users"].insert_one(m_database->mongofy(dto));
        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)
