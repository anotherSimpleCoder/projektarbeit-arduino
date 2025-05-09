#!/bin/bash
for file in ./documents/*
do
    Rscript -e 'rmarkdown::render(\"*.Rmd\")'
done