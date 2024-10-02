FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    cmake \
    # libhv-dev \
    # nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/http-server

RUN git clone https://github.com/DSCA-labs/avt113-labs-team-5.git

RUN git checkout develop

RUN git submodule update --init --recursive

RUN cd libhv-http && mkdir build 

RUN cd libhv-http/build && cmake ..

RUN cd libhv-http/build && make

EXPOSE 7777

CMD ["libhv-http/build/libhv-http"]
