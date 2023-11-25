# QMK keymaps

Personal [QMK][qmk] keymaps

[qmk]: https://github.com/qmk/qmk_firmware

## Repository structure

The main QMK repository is located in the `qmk_firmware` directory as a submodule.

All personal keymaps are located in the `keymaps` directory, and follow the [QMK keyboard directory structure][qmk_dirs], e.g.;

```
~/qmk-keymaps$ ls -R keymaps
keymaps:
splitkb

keymaps/splitkb:
kyria

keymaps/splitkb/kyria:
keymaps

keymaps/splitkb/kyria/keymaps:
malcocer

keymaps/splitkb/kyria/keymaps/malcocer:
config.h  keymap.c  rules.mk
```

[qmk-dirs]: https://docs.qmk.fm/#/config_options?id=folders

## Building firmware

Initialize and update all submodules;

```shell
~/qmk-keymaps$ git submodule update --init --recursive
```

Firmware can then by built from the repository root using the supplied [Makefile](Makefile) and usual [QMK make targets][qmk-make], e.g.;

```shell
~/qmk-keymaps$ make splitb/kyria/rev1:malcocer
~/qmk-keymaps$ make splitb/kyria/rev1:malcocer:dfu-split-left
```

The `clean` target is extended to clean the QMK submodule directory of any personal keymaps.

[qmk-make]: https://docs.qmk.fm/#/getting_started_make_guide
