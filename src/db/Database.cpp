#include "Database.hpp"

Database::Database(const mongocxx::uri& uri, const std::string& dbName)
    : m_pool(std::make_shared<mongocxx::pool>(uri)), m_databaseName(dbName)
{}

bsoncxx::document::value Database::toMongo(const oatpp::Void& polymorph) {
    oatpp::data::stream::BufferOutputStream stream;
    m_objectMapper.write(&stream, polymorph);
    bsoncxx::document::view view(stream.getData(), stream.getCurrentPosition());
    return bsoncxx::document::value(view);
}

template <typename T>
oatpp::Void Database::toModel(const bsoncxx::document::view view) {
    auto bson = oatpp::String((const char*)view.data(), view.length());
    return m_objectMapper.readFromString<oatpp::Object<T>>(bson);
}

mongocxx::collection Database::collection(const std::string& collectionName) {
    auto client = m_pool->acquire();
    return (*client)[m_databaseName][collectionName];
}
