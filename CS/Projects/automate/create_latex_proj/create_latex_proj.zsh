#!/bin/zsh
name=$1
mkdir $name
cd $name
cp ~/Documents/OSU/CS/Projects/automate/create_latex_proj/template.tex $name.tex
mkdir figures