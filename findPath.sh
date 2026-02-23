#!/usr/bin/env bash

for i in {1..7}; do
  ./findPath in$i.txt output$i.txt
  if diff -q output$i.txt out$i >/dev/null; then
    echo "Test $i passed"
  else
    echo "Test $i failed."
    diff -u output$i.txt out$i.txt
  fi
done
