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
