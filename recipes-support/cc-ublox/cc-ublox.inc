DESCRIPTION = "UBX protocol definition, used by u-blox GPS receivers."
LICENSE = "MPL-2.0"

SRC_URI = "\
    git://github.com/commschamp/cc.ublox.generated.git;protocol=https;branch=master \
"

LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

S = "${WORKDIR}/git"

PR = "r1"

DEPENDS = "cc-comms"

inherit cmake

ALLOW_EMPTY:${PN} = "1"
FILES:${PN}-dev += "${libdir}/*"
