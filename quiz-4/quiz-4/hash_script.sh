#!/bin/bash
# Hash Script: Takes a 4-digit integer and outputs its SHA-256 hash.

if [ $# -ne 1 ]; then
    echo "Usage: $0 <4-digit-integer>"
    exit 1
fi

echo -n "$1" | sha256sum | awk '{print $1}'
