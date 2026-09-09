/*
 * Copyright (c) 2016 Daniel Pirch
 *
 * Use of this source code is governed by a BSD-style license
 * that can be found in the LICENSE file in the root of the source
 * tree. An additional intellectual property rights grant can be found
 * in the file PATENTS.  All contributing project authors may
 * be found in the AUTHORS file in the root of the source tree.
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// replacements for WebRTC's various assert-like macros
#if defined(__GNUC__) || defined(__clang__) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#define RTC_COMPILE_ASSERT(expr) _Static_assert(expr, #expr)
#else
#define RTC_COMPILE_ASSERT(expr) typedef char rtc_ca_[(expr) ? 1 : -1]
#endif
#define RTC_DCHECK(expr) assert(expr)
#define RTC_DCHECK_GT(a,b) assert((a) > (b))
#define RTC_DCHECK_LT(a,b) assert((a) < (b))
#define RTC_DCHECK_LE(a,b) assert((a) <= (b))

// from webrtc/base/sanitizer.h
#ifdef __has_attribute
#if __has_attribute(no_sanitize)
#define RTC_NO_SANITIZE(what) __attribute__((no_sanitize(what)))
#endif
#endif
#ifndef RTC_NO_SANITIZE
#define RTC_NO_SANITIZE(what)
#endif

#define arraysize(a) (sizeof (a) / sizeof *(a))


#endif // COMMON_H_
