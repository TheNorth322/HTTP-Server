FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    cmake \
    # libhv-dev \
    # nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/
RUN git clone --recurse-submodules https://github.com/TheNorth322/HTTP-Server.git

WORKDIR /usr/src/HTTP-Server/libhv-http
RUN mkdir build && cd build && cmake .. && make

EXPOSE 7777

CMD ["libhv-http/build/libhv-http"]

