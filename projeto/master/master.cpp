#include "httplib.h"
#include "json.hpp"
#include <future>

using json = nlohmann::json;

json call_slave(std::string host, int port, std::string path, std::string data) {
    httplib::Client cli(host, port);
    auto health = cli.Get("/health"); // Consulta /health antes [cite: 17]
    if (health && health->status == 200) {
        auto res = cli.Post(path.c_str(), data, "text/plain");
        if (res) return json::parse(res->body);
    }
    return json::object();
}

int main() {
    httplib::Server svr;
    svr.Post("/processar", [](const httplib::Request& req, httplib::Response& res) {
        // Uso de std::async para paralelismo (threads) [cite: 13, 26]
        auto f1 = std::async(std::launch::async, call_slave, "slave1", 8081, "/palavras", req.body);
        auto f2 = std::async(std::launch::async, call_slave, "slave2", 8082, "/tamanho", req.body);

        json response;
        response["estatisticas"] = f1.get();
        response["extremos"] = f2.get();
        res.set_content(response.dump(), "application/json");
    });
    svr.listen("0.0.0.0", 8080);
    return 0;
}