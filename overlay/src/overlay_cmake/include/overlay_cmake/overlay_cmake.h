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

#ifndef OVERLAY_CMAKE__OVERLAY_CMAKE_H_
#define OVERLAY_CMAKE__OVERLAY_CMAKE_H_

#ifdef __cplusplus
extern "C" {
#endif

const char ** overlay_cmake_func(void);
void overlay_cmake_free(const char ** arr);

#ifdef __cplusplus
}
#endif

#endif  // OVERLAY_CMAKE__OVERLAY_CMAKE_H_
