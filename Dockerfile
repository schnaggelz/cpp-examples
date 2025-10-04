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
    build-essential
RUN apt clean

# Switch user and set working directory
USER ubuntu
WORKDIR /home/ubuntu
