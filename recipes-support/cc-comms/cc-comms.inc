DESCRIPTION = "Main Library of CommsChampion Ecosystem, used to defined binary communication protocols."
LICENSE = "MPL-2.0"

SRC_URI = "git://github.com/commschamp/comms.git;protocol=https;branch=master"
LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

S = "${WORKDIR}/git"

PR = "r1"

inherit cmake

ALLOW_EMPTY:${PN} = "1"
FILES:${PN}-dev += "${libdir}/*"



