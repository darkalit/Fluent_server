#include "AppComponent.hpp"
#include "controller/PingController.hpp"
#include "controller/UserController.hpp"

#include <oatpp-swagger/Controller.hpp>
#include <oatpp/network/Server.hpp>

#include <mongocxx/instance.hpp>

#include <iostream>

void run() {
    mongocxx::instance instance{};

    AppComponent appComponent;

    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    oatpp::web::server::api::Endpoints docEndpoints;

    docEndpoints.append(router->addController(PingController::createShared())->getEndpoints());

    router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
    router->addController(PingController::createShared());
    router->addController(UserController::createShared());
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
    oatpp::network::Server server(connectionProvider, connectionHandler);

    OATPP_LOGI("FluentApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

    server.run();
}

int main(int argc, const char* argv[]) {
    oatpp::base::Environment::init();

    run();

    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

    oatpp::base::Environment::destroy();
    return 0;
}
