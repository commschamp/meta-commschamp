DESCRIPTION = "MQTT v3.1.1 client library/applications."
LICENSE = "MPL-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9741c346eef56131163e13b9db1241b3"

SRC_URI = "git://github.com/commschamp/cc.mqtt311.libs.git;protocol=https;branch=master"

S = "${WORKDIR}/git"

PR = "r1"

inherit cmake

DEPENDS = "\
    cc-comms \
    cc-mqtt311 \
"

PACKAGECONFIG ??= "cc_mqtt311_client_lib cc_mqtt311_client_apps cc_mqtt311_client_apps_with_tls"
PACKAGECONFIG[cc_mqtt311_client_lib] = "-DCC_MQTT311_CLIENT_DEFAULT_LIB=ON, -DCC_MQTT311_CLIENT_DEFAULT_LIB=OFF"
PACKAGECONFIG[cc_mqtt311_client_apps] = "\
    -DCC_MQTT311_CLIENT_DEFAULT_LIB=ON -DCC_MQTT311_CLIENT_APPS=ON -DCC_MQTT311_CLIENT_APPS_WITH_OPENSSL=ON, \
    -DCC_MQTT311_CLIENT_APPS=OFF, \
    boost \
"

PACKAGECONFIG[cc_mqtt311_client_apps_with_tls] = "\
    -DCC_MQTT311_CLIENT_APPS_WITH_OPENSSL=ON, \
    -DCC_MQTT311_CLIENT_APPS_WITH_OPENSSL=OFF, \
    openssl \
"

EXTRA_OECMAKE += "\
    -DCC_MQTT311_WARN_AS_ERR=OFF \
"

FILES:${PN}-dev += "${libdir}/cc_mqtt311_client/*"
