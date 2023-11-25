# Make config #################################################################

SHELL=/bin/bash
.SHELLFLAGS=-O globstar -c

# Variables ###################################################################

DIR_QMK=qmk_firmware
DIR_KEYMAPS=keymaps

# Rules #######################################################################

# Firmware ------------------------------------------------------------------ #

# Catch-all
%: KEYBOARD_KEYMAP=$(subst :, ,$@)
%: KEYMAP=$(word 2,${KEYBOARD_KEYMAP})
%: KEYBOARD=$(word 1,$(subst /, ,${KEYBOARD_KEYMAP}))
%:
	cd ${DIR_KEYMAPS} \
		&& cp --recursive --parents ${KEYBOARD} ../${DIR_QMK}/keyboards
	cd ${DIR_QMK} \
		&& ./util/docker_build.sh $@

# Phonies ------------------------------------------------------------------- #

clean:
	-cd ${DIR_KEYMAPS} \
		&& for KEYMAP in **/keymaps/*; do \
			rm -r ../${DIR_QMK}/keyboards/$$KEYMAP; \
		done
	make -C ${DIR_QMK} clean

distclean: clean
	make -C ${DIR_QMK} distclean

.PHONY: \
	clean \
	distclean \

