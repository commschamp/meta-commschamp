DESCRIPTION = "Code generator"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=b1e01b26bacfc2232046c90a330332b3"

DEPENDS = "libxml2"

SRC_URI = "git://github.com/commschamp/commsdsl.git;protocol=https;branch=master"

S = "${WORKDIR}/git"

PR = "r1"

inherit cmake 

BBCLASSEXTEND = "native nativesdk"

EXTRA_OECMAKE += "\
    -DCOMMSDSL_WARN_AS_ERR=OFF \
    -DCOMMSDSL_BUILD_COMMSDSL2TEST=ON \
    -DCOMMSDSL_BUILD_COMMSDSL2TOOLS_QT=ON \
    -DCOMMSDSL_BUILD_COMMSDSL2SWIG=ON \
"


