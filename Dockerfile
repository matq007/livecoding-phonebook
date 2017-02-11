FROM ubuntu:12.04

RUN apt-get update -qq
RUN apt-get install -y software-properties-common python-software-properties

RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN add-apt-repository ppa:h-rayflood/llvm
RUN add-apt-repository ppa:george-edison55/precise-backports
RUN apt-get update  
RUN apt-get install -y sudo build-essential clang-3.4 make cmake \
    libgtest-dev autotools-dev libicu-dev build-essential libboost-all-dev

# GTEST
WORKDIR /usr/src/gtest
RUN cmake . 
RUN make 
RUN mv libg* /usr/lib 
RUN ldconfig 

# BUILD
WORKDIR /
RUN mkdir /phoneboook
WORKDIR /phonebook
ADD . /phonebook 
RUN cmake . && make && ./livecoding-phonebook-test

