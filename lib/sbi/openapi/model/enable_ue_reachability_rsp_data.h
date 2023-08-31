/*
 * enable_ue_reachability_rsp_data.h
 *
 * Data within a Namf_MT EnableUEReachability response
 */

#ifndef _OpenAPI_enable_ue_reachability_rsp_data_H_
#define _OpenAPI_enable_ue_reachability_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_enable_ue_reachability_rsp_data_s OpenAPI_enable_ue_reachability_rsp_data_t;
typedef struct OpenAPI_enable_ue_reachability_rsp_data_s {
    char* reachability;
    char *supported_features;
} OpenAPI_enable_ue_reachability_rsp_data_t;

OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_create(
        char* reachability,
        char *supported_features
);
void OpenAPI_enable_ue_reachability_rsp_data_free(OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data);
OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_parseFromJSON(cJSON *enable_ue_reachability_rsp_dataJSON);
cJSON *OpenAPI_enable_ue_reachability_rsp_data_convertToJSON(OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data);
OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_copy(OpenAPI_enable_ue_reachability_rsp_data_t *dst, OpenAPI_enable_ue_reachability_rsp_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_enable_ue_reachability_rsp_data_H_ */

