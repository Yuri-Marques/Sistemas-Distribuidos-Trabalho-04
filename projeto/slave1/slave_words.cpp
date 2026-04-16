#include "httplib.h"
#include "json.hpp"
#include <set>
#include <sstream>

using json = nlohmann::json;

int main() {
    httplib::Server svr;
    svr.Get("/health", [](const auto&, auto& res) { res.set_content("OK", "text/plain"); });

    svr.Post("/palavras", [](const httplib::Request& req, httplib::Response& res) {
        std::stringstream ss(req.body);
        std::string word;
        int total = 0;
        std::set<std::string> unique;
        while (ss >> word) { total++; unique.insert(word); }
        
        json j = {{"total", total}, {"unicas", unique.size()}};
        res.set_content(j.dump(), "application/json");
    });
    svr.listen("0.0.0.0", 8081);
    return 0;
}