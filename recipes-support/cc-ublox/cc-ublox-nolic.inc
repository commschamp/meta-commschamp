require cc-ublox.inc

SRC_URI += "\
    file://LICENSE \
"

do_patch () {
    cp ${WORKDIR}/LICENSE ${S}
}



