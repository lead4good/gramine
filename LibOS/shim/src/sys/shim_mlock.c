/* SPDX-License-Identifier: LGPL-3.0-or-later */
/* Copyright (C) 2022 Integritee AG
 *                    Frieder Paape <frieder@integritee.network>
 */

#include <stddef.h>

#include "shim_table.h"

long shim_do_mlock(__attribute__((unused)) const void* addr, __attribute__((unused)) size_t len) {
    return 0;
}

long shim_do_munlock(__attribute__((unused)) const void* addr, __attribute__((unused)) size_t len) {
    return 0;
}

long shim_do_mlockall(__attribute__((unused)) int flags) {
    return 0;
}

long shim_do_munlockall(void) {
    return 0;
}
