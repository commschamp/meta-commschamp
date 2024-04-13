# Overview
This repository is intended to be used as a git submodule as well as an extra
[layer](https://docs.yoctoproject.org/bsp-guide/bsp.html) of the [yocto project](https://www.yoctoproject.org/)
when building embedded Linux distribution.

# Provided Recipes

- [cc-comms](recipes-support/cc-comms) - Recipe(s) for the [COMMS Library](https://github.com/commschamp/comms).
- [cc-commsdsl](recipes-applications/cc-commsdsl) - Recipe(s) for the [commsdsl](https://github.com/commschamp/commscommsdsl) code generators.
- [cc-mqtt311](recipes-support/cc-mqtt311) - Recipe(s) for the [cc.mqtt311.generated](https://github.com/commschamp/cc.mqtt311.generated).
- [cc-mqtt5-libs](recipes-support/cc-mqtt5-libs) - Recipe(s) for the [cc.mqtt5.libs](https://github.com/commschamp/cc.mqtt5.libs).
- [cc-mqtt5](recipes-support/cc-mqtt5) - Recipe(s) for the [cc.mqtt5.generated](https://github.com/commschamp/cc.mqtt5.generated).
- [cc-mqttsn](recipes-support/cc-mqttsn) - Recipe(s) for the [cc.mqttsn.generated](https://github.com/commschamp/cc.mqttsn.generated).
- [cc-mqttsn-libs](recipes-support/cc-mqttsn-libs) - Recipe(s) for the [cc.mqttsn.libs](https://github.com/commschamp/cc.mqttsn.libs).
- [cc-ublox](recipes-support/cc-ublox) - Recipe(s) for the [cc.ublox.generated](https://github.com/commschamp/cc.ublox.generated).
- [cc-x509](recipes-support/cc-x509) - Recipe(s) for the [cc.x509.generated](https://github.com/commschamp/cc.x509.generated).

# Supported Yocto Versions
This meta layer follows the convention of branch names after the [yocto releases](https://wiki.yoctoproject.org/wiki/Releases).
In most cases the branch names will follow the same hashes until the backward compatibility of the recipe syntax is broken,
like it happened with the **honister** release.

The **master** branch will follow the latest yocto **LTS** release, and the [release tags](https://github.com/commschamp/meta-commschamp/releases)
will be assigned to the commits on the **master** branch.
They will serve as an announcement that all the branches have been updated and their latest updates
could be pulled in.

Note that the names of the supported yocto releases are listed in the **LAYERSERIES_COMPAT_commschamp** variable inside
the [conf/layer.conf](conf/layer.conf). In case newer version of yocto is being used, just update the variable accordingly
and then submit a pull-request with the update.

In case some yocto release is EOL, then its relevant branch in this repository may also stop receiving
updates of the latest [CommsChampion Ecosystem](https://commschamp.github.io/) projects releases.

# PACKAGECONFIG of cc-commsdsl
By default the `cc-commsdsl` recipe produces single **commsdsl2comms** code generator. However, the recipe defines multiple
**PACKAGECONFIG** features named after the possible code generator binary name. To enable the relevant code generator use
**PACKAGECONFIG:pn-cc-commsdsl** variable assignment in the `local.conf` or machine configuration file.
```
PACKAGECONFIG:pn-cc-commsdsl = "commsdsl2swig commsdsl2emscripten"
```

# PACKAGECONFIG of cc-mqttsn-libs
By default the `cc-mqttsn-libs` recipe produces static libraries for both client and gateway. The recipe also allows
adding Qt5 based applications for UDP I/O link. To enable them use appropriate **PACKAGECONFIG** assignment in the
`local.conf` or machine configuration file.
```
PACKAGECONFIG:append:pn-cc-mqttsn-libs = " cc_mqttsn_client_udp_apps cc_mqttsn_gateway_udp_apps"
```
Note that it will bring up `qt5base` package as a dependency.

# PACKAGECONFIG of cc-mqtt5-libs
By default the `cc-mqtt5-libs` recipe produces static mqtt5 client library as well as application tools. The recipe also allows
adding / removing features using **PACKAGECONFIG** assignment in the
`local.conf` or machine configuration file.
```
PACKAGECONFIG:append:pn-cc-mqtt5-libs = " cc_mqtt5_client_lib"
```
Note that application tools it will bring up `boost` package as a dependency.

# Extra Tips
When generating and using SDK for the external target application development add the following lines to the image recipe:
```
# Add the required headers only libraries from the CommsChampion Ecosystem
TOOLCHAIN_TARGET_TASK += "cc-comms-dev"
TOOLCHAIN_TARGET_TASK += "cc-ublox-dev"
...

# Add the code generators to the host sysroot
TOOLCHAIN_HOST_TASK += "nativesdk-cc-commsdsl"
```

In case some other project requires code generators from the CommsChampion Ecosystem add **cc-commsdsl-native** to the dependencies
```
DEPENDS = "cc-commsdsl-native cc-comms"
```
