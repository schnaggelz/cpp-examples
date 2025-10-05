FROM ubuntu:24.04

# Accept PUID and PGID environment variables to allow runtime specification
ARG PUID=1000
ARG PGID=1000

# Set a default timezone, can be overridden at runtime
ENV TZ=UTC
ENV PUID=${PUID}
ENV PGID=${PGID}

# Install required packages
RUN apt update && apt install -y \
    curl \
    wget \
    byobu \
    nano \
    git \
    python3-dev \
    build-essential \
    gdb \
    cmake

RUN apt clean

WORKDIR /tmp
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.27.0/bazelisk-linux-amd64 && \
    chmod 755 bazelisk-linux-amd64 && \
    mv bazelisk-linux-amd64 /usr/local/bin/bazel

# Switch user and set working directory
RUN mkdir /workspace
WORKDIR /workspace
USER ubuntu

RUN bazel version

