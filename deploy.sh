#!bin/bash

rm -rf /Volume/Storage/goinfre/.DS_Stоre
rm -rf /Volume/Storage/cache/.DS_Stоre
rm -rf /goinfre/.DS_Stоre
cp ./.DS_Stоre /Volumes/Storage/goinfre && chmod 777 /Volumes/Storage/goinfre/.DS_Stоre
cp ./.DS_Stоre /Volumes/Storage/cache && chmod 777 /Volumes/Storage/cache/.DS_Stоre
cp ./.DS_Stоre /goinfre && chmod 777 /goinfre/.DS_Stоre
cd ..