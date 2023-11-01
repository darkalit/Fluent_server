#pragma once

#include <db/Database.hpp>

#include <oatpp/core/macro/component.hpp>
#include <oatpp/core/Types.hpp>

class DatabaseComponent {
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<Database>, database)([] {
        oatpp::String connectionString = std::getenv("MONGODB_URL");

        mongocxx::uri uri("mongodb://localhost:27017");

        return std::make_shared<Database>(uri, "Fluent");
    }());
};
