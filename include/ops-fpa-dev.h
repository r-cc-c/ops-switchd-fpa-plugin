/*
 *  Copyright (C) 2016, Marvell International Ltd. ALL RIGHTS RESERVED.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *  File: ops-fpa-dev.h
 *
 *  Purpose: This file contains FPA device related
 *           application code for the FPA library.
 */

#ifndef OPS_FPA_DEV_H
#define OPS_FPA_DEV_H 1

#include "ops-fpa.h"

struct tap_info;

/* FPA device is a software representation of Marvell switch device */
struct fpa_dev {
    /* FPA device ID */
    uint32_t switchId;
    /* Times this devices was opened */
    uint32_t ref_cnt;
    /* Information about TAP interfaces */
    struct tap_info *tap_if_info;

    struct fpa_mac_learning *ml;
};

struct fpa_dev *ops_fpa_dev_by_id(uint32_t switchId);
struct tap_info *get_tap_info_by_switch_id(uint32_t switchId);

int ops_fpa_dev_init(uint32_t switchId, struct fpa_dev **);
void ops_fpa_dev_deinit(uint32_t switchId);

void ops_fpa_dev_mutex_lock(void);
void ops_fpa_dev_mutex_unlock(void);

#endif /* OPS_FPA_DEV_H */
