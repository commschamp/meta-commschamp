require cc-mqtt5.inc

SRC_URI += "\
    file://LICENSE \
"

do_patch () {
    cp ${WORKDIR}/LICENSE ${S}
}



