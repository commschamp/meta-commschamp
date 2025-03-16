DESCRIPTION = "MQTT v5 client library/applications."
LICENSE = "MPL-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9741c346eef56131163e13b9db1241b3"

SRC_URI = "git://github.com/commschamp/cc.mqtt5.libs.git;protocol=https;branch=master"

S = "${WORKDIR}/git"

PR = "r1"

inherit cmake 

DEPENDS = "\
    cc-comms \
    cc-mqtt5 \
"

PACKAGECONFIG ??= "cc_mqtt5_client_lib cc_mqtt5_client_apps cc_mqtt5_client_apps_with_tls"
PACKAGECONFIG[cc_mqtt5_client_lib] = "-DCC_MQTT5_CLIENT_DEFAULT_LIB=ON, -DCC_MQTT5_CLIENT_DEFAULT_LIB=OFF"
PACKAGECONFIG[cc_mqtt5_client_apps] = "\
    -DCC_MQTT5_CLIENT_DEFAULT_LIB=ON -DCC_MQTT5_CLIENT_APPS=ON, \
    -DCC_MQTT5_CLIENT_APPS=OFF, \
    boost \
"
PACKAGECONFIG[cc_mqtt5_client_apps_with_tls] = "\
    -DCC_MQTT5_CLIENT_APPS_WITH_OPENSSL=ON, \
    -DCC_MQTT5_CLIENT_APPS_WITH_OPENSSL=OFF, \
    openssl \
"

EXTRA_OECMAKE += "\
    -DCC_MQTT5_WARN_AS_ERR=OFF \
"

FILES:${PN}-dev += "${libdir}/cc_mqtt5_client/*"
