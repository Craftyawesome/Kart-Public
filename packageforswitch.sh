#!/bin/sh
INSTALLERURL="https://github.com/STJr/Kart-Public/releases/download/v1.1/srb2kart-v11-Installer.exe"
PATCHURL="https://github.com/STJr/Kart-Public/releases/download/v1.1/srb2kart-v11-Patch.zip"
DOWNLOADCMD="curl -Lo"

cd assets
rm *.srb *.kart *.pk3 *.dta *.wad
${DOWNLOADCMD} kartinstaller.exe ${INSTALLERURL}
7z e -y -aoa kartinstaller.exe "*.srb" "*.kart" "*.pk3" "*.dta" "*.wad"
rm kartinstaller.exe
cd patch
rm *.srb *.kart *.pk3 *.dta *.wad
${DOWNLOADCMD} kartpatch.zip ${PATCHURL}
unzip -o -j kartpatch.zip "*.srb" "*.kart" "*.pk3" "*.dta" "*.wad"
rm kartpatch.zip
cd ../..
make -C src/ SWITCH=1 clean
make -C src/ SWITCH=1