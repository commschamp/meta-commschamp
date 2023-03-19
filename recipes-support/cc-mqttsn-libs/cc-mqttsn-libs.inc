DESCRIPTION = "MQTT-SN client/gateway libraries/applications."
LICENSE = "MPL-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

SRC_URI = "git://github.com/commschamp/cc.mqttsn.libs.git;protocol=https;branch=master"

S = "${WORKDIR}/git"

PR = "r1"

inherit cmake 

DEPENDS = "\
    cc-comms \
    cc-mqttsn \
"

PACKAGECONFIG ??= "cc_mqttsn_client_lib cc_mqttsn_gateway_lib"
PACKAGECONFIG[cc_mqttsn_client_lib] = "-DCC_MQTTSN_CLIENT_DEFAULT_LIB=ON, -DCC_MQTTSN_CLIENT_DEFAULT_LIB=OFF"
PACKAGECONFIG[cc_mqttsn_gateway_lib] = "-DCC_MQTTSN_BUILD_GATEWAY=ON, -DCC_MQTTSN_BUILD_GATEWAY=OFF, cc-mqtt311"
PACKAGECONFIG[cc_mqttsn_client_udp_apps] = "-DCC_MQTTSN_BUILD_CLIENT_APPS=ON, -DCC_MQTTSN_BUILD_CLIENT_APPS=OFF, qtbase"
PACKAGECONFIG[cc_mqttsn_gateway_udp_apps] = "-DCC_MQTTSN_BUILD_GATEWAY_APPS=ON, -DCC_MQTTSN_BUILD_GATEWAY_APPS=OFF, cc-mqtt311 qtbase"

EXTRA_OECMAKE += "\
    -DCC_MQTTSN_WARN_AS_ERR=OFF \
"

FILES:${PN}-dev += "${libdir}/cc_mqttsn_client/* ${libdir}/cc_mqttsn_gateway/*"
