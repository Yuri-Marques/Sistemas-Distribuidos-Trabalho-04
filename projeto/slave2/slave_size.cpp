#include "httplib.h"
#include "json.hpp"
#include <sstream>

using json = nlohmann::json;

int main() {
    httplib::Server svr;
    svr.Get("/health", [](const auto&, auto& res) { res.set_content("OK", "text/plain"); });

    svr.Post("/tamanho", [](const httplib::Request& req, httplib::Response& res) {
        std::stringstream ss(req.body);
        std::string word, short_w, long_w;
        bool first = true;
        while (ss >> word) {
            if (first) { short_w = long_w = word; first = false; }
            if (word.length() < short_w.length()) short_w = word;
            if (word.length() > long_w.length()) long_w = word;
        }
        json j = {{"curta", short_w}, {"longa", long_w}};
        res.set_content(j.dump(), "application/json");
    });
    svr.listen("0.0.0.0", 8082);
    return 0;
}