#!/bin/sh
INSTALLERURL="https://github.com/STJr/Kart-Public/releases/download/v1.6/srb2kart-v16-Installer.exe"
PATCHURL="https://github.com/STJr/Kart-Public/releases/download/v1.6/srb2kart-v16-patcher.exe"
DOWNLOADCMD="curl -Lo"

cd assets
rm *.srb *.kart *.pk3 *.dta *.wad *.dat mdls/*/*
${DOWNLOADCMD} kartinstaller.exe ${INSTALLERURL}
7z x -y -aoa kartinstaller.exe "*.srb" "*.kart" "*.pk3" "*.dta" "*.wad" "*.dat" "mdls/*/*"
rm kartinstaller.exe
cd ../..