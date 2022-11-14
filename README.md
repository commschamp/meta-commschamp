# Overview
This repository is intended to be used as a git submodule as well as an extra
[layer](https://docs.yoctoproject.org/bsp-guide/bsp.html) of the [yocto project](https://www.yoctoproject.org/)
when building embedded Linux distribution.

# Provided Recipes

- [cc-comms](recipes-support/cc-comms) - Recipe(s) for the [COMMS Library](https://github.com/commschamp/comms).
- [cc-commsdsl](recipes-applications/cc-commsdsl) - Recipe(s) for the [commsdsl](https://github.com/commschamp/commscommsdsl) code generators.
- [cc-mqtt311](recipes-support/cc-mqtt311) - Recipe(s) for the [cc.mqtt311.generated](https://github.com/commschamp/cc.mqtt311.generated).
- [cc-mqtt5](recipes-support/cc-mqtt5) - Recipe(s) for the [cc.mqtt5.generated](https://github.com/commschamp/cc.mqtt5.generated).
- [cc-mqttsn](recipes-support/cc-mqttsn) - Recipe(s) for the [cc.mqttsn.generated](https://github.com/commschamp/cc.mqttsn.generated).
- [cc-ublox](recipes-support/cc-ublox) - Recipe(s) for the [cc.ublox.generated](https://github.com/commschamp/cc.ublox.generated).
- [cc-x509](recipes-support/cc-x509) - Recipe(s) for the [cc.x509.generated](https://github.com/commschamp/cc.x509.generated).

# Some Tips
When generating and using SDK for the external target application development add the following lines to the image recipe:
```
# Add the required headers only libraries from the CommsChampion Ecosystem
TOOLCHAIN_TARGET_TASK += "cc-comms-dev"
TOOLCHAIN_TARGET_TASK += "cc-ublox-dev"
...

# Add the code generators to the host sysroot
TOOLCHAIN_HOST_TASK += "nativesdk-cc-commsdsl"
```

In case some other project requires code generators from the CommsChampion Ecosystem add "cc-commsdsl-native" to the dependencies
```
DEPENDS = "cc-commsdsl-native cc-comms"
```
