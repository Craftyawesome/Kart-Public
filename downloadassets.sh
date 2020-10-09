#!/bin/sh
INSTALLERURL="https://github.com/STJr/Kart-Public/releases/download/v1.3/srb2kart-v13-Installer.exe"
PATCHURL="https://github.com/STJr/Kart-Public/releases/download/v1.3/srb2kart-v13-patcher.exe"
DOWNLOADCMD="curl -Lo"

cd assets
rm *.srb *.kart *.pk3 *.dta *.wad
${DOWNLOADCMD} kartinstaller.exe ${INSTALLERURL}
7z e -y -aoa kartinstaller.exe "*.srb" "*.kart" "*.pk3" "*.dta" "*.wad"
rm kartinstaller.exe
cd patch
rm *.srb *.kart *.pk3 *.dta *.wad
${DOWNLOADCMD} kartpatcher.exe ${PATCHURL}
7z e -y -aoa kartpatcher.exe "*.srb" "*.kart" "*.pk3" "*.dta" "*.wad"
rm kartpatcher.exe
cd ../..