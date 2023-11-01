#pragma once

#include <oatpp-mongo/bson/mapping/ObjectMapper.hpp>

#include <mongocxx/pool.hpp>
#include <mongocxx/client.hpp>
#include <bsoncxx/document/value.hpp>

class Database {
public:
    Database(const mongocxx::uri& uri, const std::string& dbName);
    bsoncxx::document::value toMongo(const oatpp::Void& polymorph);

    template <typename T>
    oatpp::Void toModel(const bsoncxx::document::view view);

    mongocxx::collection collection(const std::string& collectionName);

private:
    std::shared_ptr<mongocxx::pool> m_pool;
    std::string m_databaseName;
    oatpp::mongo::bson::mapping::ObjectMapper m_objectMapper;
};
