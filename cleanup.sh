#!/usr/bin/env bash
set -e
set -x

for ext in exe exp lib pdb
do
  find . -name "*.${ext}" -type f | xargs rm -f
done
