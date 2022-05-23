#!/usr/bin/env bash

for i in $(ls | grep .ppm); do convert $i ${i:0:-4}.jpg; done
