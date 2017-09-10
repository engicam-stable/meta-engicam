# Copyright (C) 2014 O.S. Systems Software LTDA.

SUMMARY = "Remote debugging tools for QtCreator integration"
LICENSE = "MIT"

inherit packagegroup

# Override by distro if needed
VIRTUAL-RUNTIME_qtcreator-debug-ssh-daemon ?= "openssh-sshd"

RDEPENDS_${PN}_icore = " \
    gdbserver \
    ${VIRTUAL-RUNTIME_qtcreator-debug-ssh-daemon} \
    openssh-sftp-server \
    qtdeclarative-plugins \
"
RDEPENDS_${PN}_gea = " \
    gdbserver \
    ${VIRTUAL-RUNTIME_qtcreator-debug-ssh-daemon} \
    openssh-sftp-server \
"
