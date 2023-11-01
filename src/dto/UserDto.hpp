#pragma once

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>
#include <oatpp-mongo/bson/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Role, v_int32,
     VALUE(USER, 0, "USER"),
     VALUE(ADMIN, 0, "ADMIN")
)

class UserDto : public oatpp::DTO {
    DTO_INIT(UserDto, DTO);

    // DTO_FIELD(oatpp::mongo::bson::ObjectId, _id);
    DTO_FIELD(String, username);
    DTO_FIELD(String, email);
    DTO_FIELD(String, password);
    DTO_FIELD(Enum<Role>::AsString, role);
};

#include OATPP_CODEGEN_END(DTO)
