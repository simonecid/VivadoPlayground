#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /users/sb17498/VivadoPlayground/First_Test/First_Test/.autopilot/db/a.g.bc ${1+"$@"}
