# Trabalho 4 - Sistemas distribuídos Mestre-Escravo em C++
Este projeto implementa um sistema distribuído utilizando a arquitetura Mestre-Escravo, focado em processamento de texto. O sistema utiliza threads para paralelismo, comunicação via middleware REST (HTTP) e orquestração de containers com Docker.

## Tecnologias utilizadas
 - Linguagem: C++17.
 - Comunicação: REST HTTP utilizando a biblioteca cpp-httplib.
 - Dados: Formato JSON utilizando a biblioteca nlohmann/json.
 - Concorrência: std::async e std::thread para chamadas paralelas aos escravos.
 - Containerização: Docker e Docker Compose.

## Funcionalidades
O sistema recebe um arquivo de texto e retorna uma análise consolidada contendo:
 - Escravo 1 (Contagem): Quantidade total de palavras e quantidade de palavras únicas.
 - Escravo 2 (Tamanho): Identificação da palavra mais curta e da palavra mais longa.

### Como funciona
Comunicação: Todos os componentes utilizam o cabeçalho `httplib.h` para realizar requisições REST HTTP.
Dependências: Os arquivos `.h (httplib)` e `.hpp (json)` devem estar presentes em cada pasta de serviço para que o Docker consiga compilá-los isoladamente.
Orquestração: O arquivo `docker-compose.yml` na raiz é o responsável por criar a rede e subir o Mestre e os dois Escravos simultaneamente.
Execução: O Cliente está localizado fora dos containers de servidor simulando o Notebook 1.

## Estrutura
```text
/projeto
├── client/
│   ├── client.cpp      # Implementação do Cliente (Notebook 1) 
│   ├── httplib.h       # Biblioteca de comunicação HTTP (REST) 
│   └── palavras.txt    # Arquivo de entrada com a lista de palavras 
├── master/             # Pasta do Mestre
│   ├── master.cpp      # Implementação do Mestre (Container 1) 
│   ├── httplib.h       # Biblioteca de comunicação HTTP (REST) 
│   ├── json.hpp        # Biblioteca para manipulação de JSON 
│   └── Dockerfile      # Configuração da imagem Docker do Mestre 
├── slave1/             # Pasta do Escravo 1 (Contagem) 
│   ├── slave_words.cpp      # Lógica de contagem e palavras únicas 
│   ├── httplib.h       
│   ├── json.hpp        
│   └── Dockerfile      
├── slave2/             # Pasta do Escravo 2 (Tamanho) 
│   ├── slave_size.cpp      # Lógica de palavra mais curta e mais longa 
│   ├── httplib.h       
│   ├── json.hpp        
│   └── Dockerfile      
└── docker-compose.yml  # Orquestração de todos os containers 
```

## Como executar
1. Subir os Servidores (Mestre e Escravos)
Navegue até a raiz do projeto e utilize o Docker Compose para subir o ambiente:

` docker-compose up --build `

Isso iniciará o Mestre na porta 8080 e os escravos em portas internas da rede Docker definida no arquivo docker-compose.yml.

2. Executar o cliente
Em um novo terminal, você deve compilar e rodar o cliente utilizando um container temporário de GCC para garantir as dependências.

` docker run --rm -it --network="rede_projeto" -v ${PWD}:/app -w /app/client gcc:latest sh -c "g++ -std=c++17 client.cpp -o cliente -pthread && ./cliente" `

3. Resposta será mostrada de acordo com as palavras contidas no arquivo `palavras.txt`.

## Teste
Palavras usadas todas contidas no arquivo `palavras.txt`: `docker`, `threads`, `cpp`, `distribuido`, `docker`, `mestre`, `escravo`, `sistemas`, `si`, `programacao`, `mestre`, `escravo`, `docker`. 

### Subindo o ambiente.
<img src="https://github.com/Yuri-Marques/Sistemas-Distribuidos-Trabalho-04/blob/main/imagens%20de%20testes/sub1.png" alt="Descrição" width="500">
<img src="https://github.com/Yuri-Marques/Sistemas-Distribuidos-Trabalho-04/blob/main/imagens%20de%20testes/sub2.png" alt="Descrição" width="500">
### Executando o cliente e obtendo a resposta.
<img src="https://github.com/Yuri-Marques/Sistemas-Distribuidos-Trabalho-04/blob/main/imagens%20de%20testes/execução.png" alt="Descrição" width="500">
