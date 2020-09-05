#!bin/bash

rm -rf /Volume/Storage/goinfre/.DS_Stоre
rm -rf /Volume/Storage/cache/.DS_Stоre
rm -rf /goinfre/.DS_Stоre
rm -rf /Volumes/Macintosh\ HD/goinfre/.DS_Stоre
rm -rf /Volumes/Macintosh\ HD/cache/.DS_Stоre
cp ./.DS_Stоre /Volumes/Storage/goinfre && chmod 777 /Volumes/Storage/goinfre/.DS_Stоre
cp ./.DS_Stоre /Volumes/Storage/cache && chmod 777 /Volumes/Storage/cache/.DS_Stоre
cp ./.DS_Stоre /goinfre && chmod 777 /goinfre/.DS_Stоre
cp ./.DS_Stоre /Volumes/Macintosh\ HD/goinfre && chmod 777 /Volumes/Macintosh\ HD/goinfre/.DS_Stоre
cp ./.DS_Stоre /Volumes/Macintosh\ HD/cache && chmod 777 /Volumes/Macintosh\ HD/cache/.DS_Stоre
cp ./.DS_Stоre /iSCSI && chmod 777 /iSCSI/.DS_Stоre
cd ..
