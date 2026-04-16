FROM gcc:latest
RUN apt-get update && apt-get install -y libpthread-stubs0-dev
COPY . /app
WORKDIR /app
# Compila usando C++17 e suporte a threads [cite: 23, 26]
RUN g++ -std=c++17 *.cpp -o servico -pthread
CMD ["./servico"]