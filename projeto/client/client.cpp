#include "httplib.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("palavras.txt");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    httplib::Client cli("master", 8080);
    if (auto res = cli.Post("/processar", content, "text/plain")) {
        std::cout << "Resposta do Mestre:\n" << res->body << std::endl;
    } else {
        std::cerr << "Erro ao conectar no Mestre!" << std::endl;
    }
    return 0;
}