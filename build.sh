#!/bin/bash

mkdir dist
mkdir dist/grids

cp config.ini dist/
cp -r grids/* dist/grids
cd dist && make