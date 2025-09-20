FROM ubuntu:16.04

RUN apt update && \
    apt install -y g++ vim && \ 
    rm -rf /var/lib/apt/lists/*

COPY hello.cpp /app/            
WORKDIR /app

RUN g++ -o hello hello.cpp     

CMD ["./hello"]