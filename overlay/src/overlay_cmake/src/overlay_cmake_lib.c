// Copyright 2026 Scott K Logan
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdlib.h>
#include <string.h>

#include <underlay_cmake/underlay_cmake.h>
#include <underlay_meson/underlay_meson.h>

#include "overlay_cmake/overlay_cmake.h"

size_t str_array_len(const char * const * arr)
{
  const char * const * cur = arr;

  if (NULL != cur) {
    while (NULL != *cur) {
      cur++;
    }
  }

  return cur - arr;
}

const char ** overlay_cmake_func(void)
{
  const char ** underlay_cmake = underlay_cmake_func();
  size_t underlay_cmake_len = str_array_len(underlay_cmake);

  const char ** underlay_meson = underlay_meson_func();
  size_t underlay_meson_len = str_array_len(underlay_meson);

  size_t ret_len = underlay_cmake_len + underlay_meson_len + 1;
  const char ** ret = calloc(ret_len + 1, sizeof(*ret));
  if (NULL == ret) {
    underlay_cmake_free(underlay_cmake);
    underlay_meson_free(underlay_meson);
    return NULL;
  }

  memcpy(&ret[0], underlay_cmake, underlay_cmake_len * sizeof(*ret));
  underlay_cmake_free(underlay_cmake);

  memcpy(&ret[underlay_cmake_len], underlay_meson, underlay_meson_len * sizeof(*ret));
  underlay_meson_free(underlay_meson);

  ret[underlay_cmake_len + underlay_meson_len] = "overlay_cmake";

  return ret;
}

void overlay_cmake_free(const char ** arr)
{
  free(arr);
}
