#! /usr/bin/bash
export UROOT=`pwd`
echo "[info]">${UROOT}/procinfo.ini
echo "total = 1">>${UROOT}/procinfo.ini
echo "">>${UROOT}/procinfo.ini
echo "[1]">>${UROOT}/procinfo.ini
echo "strName = ucore">>${UROOT}/procinfo.ini
nm --radix=d ${UROOT}/bin/kernel|gawk '{print $3,"=",$1}' >>${UROOT}/procinfo.ini
${UROOT}/tools/parsestruct >>${UROOT}/procinfo.ini
nm --radix=d ${UROOT}/bin/kernel|gawk '{print "target_ulong",$3,";"}' >${UROOT}/ucore_kernel_procinfo.h
${UROOT}/tools/parsestruct >${UROOT}/ucore_struct.ini
cat ${UROOT}/ucore_struct.ini|gawk '{print "target_ulong",$1,";"}' >>${UROOT}/ucore_kernel_procinfo.h

