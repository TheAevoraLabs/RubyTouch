// =============================================================================
// embedded_assets.cpp — Mobile implementation & stb_image provider
// Ruby Touch loads all assets from Android APK assets/ or filesystem.
// =============================================================================

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "platform/embedded_assets.h"

extern "C" {

bool embedded_asset(const char* name, const unsigned char** data, size_t* size) {
    (void)name;
    if (data) *data = nullptr;
    if (size) *size = 0;
    return false;
}

bool embedded_asset_has_prefix(const char* prefix) {
    (void)prefix;
    return false;
}

bool asset_decode_image(const unsigned char* data, size_t size,
                        unsigned char** out, int* w, int* h) {
    if (!data || size == 0 || !out || !w || !h) return false;
    int channels = 0;
    *out = stbi_load_from_memory(data, (int)size, w, h, &channels, 4);
    return (*out != nullptr);
}

void asset_image_free(unsigned char* px) {
    if (px) stbi_image_free(px);
}

}
