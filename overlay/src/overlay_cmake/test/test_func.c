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

#include <stdio.h>
#include <string.h>

#include "overlay_cmake/overlay_cmake.h"

static int strcmp_or_null(const char * lhs, const char * rhs)
{
  if (NULL == lhs) {
    if (NULL == rhs) {
      return 0;
    } else {
      return 1;
    }
  } else if (NULL == rhs) {
    return -1;
  }

  return strcmp(lhs, rhs);
}

static int str_array_cmp(const char * const * lhs, const char * const * rhs)
{
  int ret;

  if (NULL == lhs) {
    if (NULL == rhs) {
      return 0;
    } else {
      return 1;
    }
  } else if (NULL == rhs) {
    return -1;
  }

  while (1) {
    ret = strcmp_or_null(*lhs, *rhs);
    if (0 != ret || NULL == *lhs) {
      break;
    }

    lhs++;
    rhs++;
  }

  return ret;
}

static int check_overlay_func()
{
  printf("Checking overlay_func...");

  static const char * const expected[] = {
    "underlay_cmake",
    "underlay_meson",
    "overlay_cmake",
    NULL,
  };

  const char ** actual = overlay_cmake_func();

  int ret = str_array_cmp(expected, actual);

  overlay_cmake_free(actual);

  if (ret) {
    printf("failed.\n");
  } else {
    printf("success.\n");
  }

  return ret;
}

int main(int argc, char * argv[])
{
  (void)argc;
  (void)argv;

  int ret = 0;

  ret |= check_overlay_func();

  return ret;
}
