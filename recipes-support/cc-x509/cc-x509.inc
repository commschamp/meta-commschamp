DESCRIPTION = "X.509 public key infrastructure implemented using COMMS library from the CommsChampion Ecosystem."
LICENSE = "MPL-2.0"

SRC_URI = "\
    git://github.com/commschamp/cc.x509.generated.git;protocol=https;branch=master \
    file://LICENSE \
"

LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

S = "${WORKDIR}/git"

PR = "r1"

DEPENDS = "cc-comms"

inherit cmake

ALLOW_EMPTY_${PN} = "1"
FILES_${PN}-dev += "${libdir}/*"

do_patch () {
    cp ${WORKDIR}/LICENSE ${S}
}



