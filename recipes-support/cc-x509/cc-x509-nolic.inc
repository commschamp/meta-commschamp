require cc-x509.inc

SRC_URI += "\
    file://LICENSE \
"

LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

do_patch () {
    cp ${WORKDIR}/LICENSE ${S}
}



