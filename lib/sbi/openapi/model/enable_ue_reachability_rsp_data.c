
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "enable_ue_reachability_rsp_data.h"

OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_create(
        char* reachability,
        char *supported_features
)
{
    OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data_local_var = ogs_malloc(sizeof(OpenAPI_enable_ue_reachability_rsp_data_t));
    ogs_assert(enable_ue_reachability_rsp_data_local_var);

    enable_ue_reachability_rsp_data_local_var->reachability = reachability;
    enable_ue_reachability_rsp_data_local_var->supported_features = supported_features;

    return enable_ue_reachability_rsp_data_local_var;
}

void OpenAPI_enable_ue_reachability_rsp_data_free(OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == enable_ue_reachability_rsp_data) {
        return;
    }
    if (enable_ue_reachability_rsp_data->reachability) {
        ogs_free(enable_ue_reachability_rsp_data->reachability);
        enable_ue_reachability_rsp_data->reachability = NULL;
    }
    if (enable_ue_reachability_rsp_data->supported_features) {
        ogs_free(enable_ue_reachability_rsp_data->supported_features);
        enable_ue_reachability_rsp_data->supported_features = NULL;
    }
    ogs_free(enable_ue_reachability_rsp_data);
}

cJSON *OpenAPI_enable_ue_reachability_rsp_data_convertToJSON(OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (enable_ue_reachability_rsp_data == NULL) {
        ogs_error("OpenAPI_enable_ue_reachability_rsp_data_convertToJSON() failed [EnableUeReachabilityRspData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (enable_ue_reachability_rsp_data->reachability) {
        if (cJSON_AddStringToObject(item, "reachability", enable_ue_reachability_rsp_data->reachability) == NULL) {
            ogs_error("OpenAPI_enable_ue_reachability_rsp_data_convertToJSON() failed [reachability]");
            goto end;
        }
    }
    if (enable_ue_reachability_rsp_data->supported_features) {
        if (cJSON_AddStringToObject(item, "supportedFeatures", enable_ue_reachability_rsp_data->supported_features) == NULL) {
            ogs_error("OpenAPI_enable_ue_reachability_rsp_data_convertToJSON() failed [supported_features]");
            goto end;
        }
    }

    end:
    return item;
}

OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_parseFromJSON(cJSON *enable_ue_reachability_rsp_dataJSON)
{
    OpenAPI_enable_ue_reachability_rsp_data_t *enable_ue_reachability_rsp_data_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *reachability = NULL;
    cJSON *supported_features = NULL;

    reachability = cJSON_GetObjectItemCaseSensitive(enable_ue_reachability_rsp_dataJSON, "reachability");
    if (reachability) {
        if (!cJSON_IsString(reachability) && !cJSON_IsNull(reachability)) {
            ogs_error("OpenAPI_enable_ue_reachability_rsp_data_parseFromJSON() failed [reachability]");
            goto end;
        }
    }
    supported_features = cJSON_GetObjectItemCaseSensitive(enable_ue_reachability_rsp_dataJSON, "supportedFeatures");
    if (supported_features) {
        if (!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features)) {
            ogs_error("OpenAPI_enable_ue_reachability_rsp_data_parseFromJSON() failed [supported_features]");
            goto end;
        }
    }

    enable_ue_reachability_rsp_data_local_var = OpenAPI_enable_ue_reachability_rsp_data_create (
            reachability && !cJSON_IsNull(reachability) ? ogs_strdup(reachability->valuestring) : NULL,
            supported_features && !cJSON_IsNull(supported_features) ? ogs_strdup(supported_features->valuestring) : NULL
    );

    return enable_ue_reachability_rsp_data_local_var;
    end:
    return NULL;
}

OpenAPI_enable_ue_reachability_rsp_data_t *OpenAPI_enable_ue_reachability_rsp_data_copy(OpenAPI_enable_ue_reachability_rsp_data_t *dst, OpenAPI_enable_ue_reachability_rsp_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_enable_ue_reachability_rsp_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_enable_ue_reachability_rsp_data_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_enable_ue_reachability_rsp_data_free(dst);
    dst = OpenAPI_enable_ue_reachability_rsp_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

