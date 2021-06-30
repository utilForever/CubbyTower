FROM ubuntu:20.04
LABEL maintainer "Chris Ohk <utilforever@gmail.com>"

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    python3-dev \
    python3-pip \
    python3-venv \
    python3-setuptools \
    xorg-dev \
    libglu1-mesa-dev \
    libxrandr-dev \
    libxi-dev \
    libxxf86vm-dev \
    libxinerama-dev \
    libxcursor-dev \
    libopenal-dev \
    libvorbis-dev \
    libflac-dev \
    libudev-dev \
    cmake \
    --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

COPY . /app

WORKDIR /app/build
RUN cmake .. && \
    make -j "$(nproc)" && \
    make install && \
    bin/UnitTests

WORKDIR /
