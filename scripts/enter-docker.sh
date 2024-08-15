#!/usr/bin/env bash

docker run -it \
	--mount type=bind,source=$PWD,destination=/test1 \
	test1
