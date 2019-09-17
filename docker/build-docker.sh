#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-dashpay/mgrcd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/mgrcd docker/bin/
cp $BUILD_DIR/src/mgrc-cli docker/bin/
cp $BUILD_DIR/src/mgrc-tx docker/bin/
strip docker/bin/mgrcd
strip docker/bin/mgrc-cli
strip docker/bin/mgrc-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
