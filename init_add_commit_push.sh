#!/bin/bash

git init
git add .
git commit -m "First commit"
git remote add origin $1
git push origin master
