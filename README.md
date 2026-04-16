# Trabalho 4 - Sistema Distribuído Mestre-Escravo em C++
Este projeto implementa um sistema distribuído utilizando a arquitetura Mestre-Escravo, focado em processamento de texto. O sistema utiliza threads para paralelismo, comunicação via middleware REST (HTTP) e orquestração de containers com Docker.

## Funcionalidades
O sistema recebe um arquivo de texto e retorna uma análise consolidada contendo:
 - Escravo 1 (Contagem): Quantidade total de palavras e quantidade de palavras únicas.
 - Escravo 2 (Tamanho): Identificação da palavra mais curta e da palavra mais longa.

## Tecnologias Utilizadas
 - Linguagem: C++17.
 - Comunicação: REST HTTP utilizando a biblioteca cpp-httplib.
 - Dados: Formato JSON utilizando a biblioteca nlohmann/json.
 - Concorrência: std::async e std::thread para chamadas paralelas aos escravos.
 - Containerização: Docker e Docker Compose.

## Como Executar
1. Subir os Servidores (Mestre e Escravos)
Navegue até a raiz do projeto e utilize o Docker Compose para subir o ambiente:
´´´ docker-compose up --build ´´´
Isso iniciará o Mestre na porta 8080 e os escravos em portas internas da rede Docker definida no arquivo docker-compose.yml.

3. Executar o Cliente
Em um novo terminal, você deve compilar e rodar o cliente utilizando um container temporário de GCC para garantir as dependências.
´´´ docker run --rm -it --network="rede_projeto" -v ${PWD}:/app -w /app/client gcc:latest sh -c "g++ -std=c++17 client.cpp -o cliente -pthread && ./cliente" ´´´

