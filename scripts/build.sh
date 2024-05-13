#!/bin/bash

PROBLEM_PATH="problems/*"
GENERATOR_PATH="scripts/generate-problem.sh"
OUTPUT_PATH="results"
TIME_LIMIT=1
MEMORY_LIMIT=256

alphabet=({A..Z})
index=0
folders=$(ls -d $PROBLEM_PATH)
for folder in $folders; do
    letter=${alphabet[index]}
    echo "Generating Problem $letter $folder"
    $GENERATOR_PATH $letter $folder "$folder" $TIME_LIMIT $MEMORY_LIMIT $OUTPUT_PATH
    echo " "
    ((index++))
done
