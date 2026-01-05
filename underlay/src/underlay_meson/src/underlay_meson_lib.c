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

#include "underlay_meson/underlay_meson.h"

const char ** underlay_meson_func(void)
{
  const char ** ret = calloc(2, sizeof(*ret));
  if (NULL == ret) {
    return NULL;
  }

  ret[0] = "underlay_meson";

  return ret;
}

void underlay_meson_free(const char ** arr)
{
  free(arr);
}
