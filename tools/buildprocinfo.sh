#! /usr/bin/bash
export UROOT=`pwd`
echo "[info]">${UROOT}/procinfo.ini
echo "total = 1">>${UROOT}/procinfo.ini
echo "">>${UROOT}/procinfo.ini
echo "[1]">>${UROOT}/procinfo.ini
echo "strName = ucore">>${UROOT}/procinfo.ini
 nm --radix=d ${UROOT}/bin/kernel|gawk '{print $3,"=",$1}' >>${UROOT}/procinfo.ini
${UROOT}/tools/parsestruct >>${UROOT}/procinfo.ini
