/*
 * Copyright (c) 2008 Tilman Sauerbeck (tilman at xmms org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _SUBMISSION_H
#define _SUBMISSION_H

#include <stdint.h>
#include <time.h>
#include <xmmsclient/xmmsclient.h>
#include "strbuf.h"

typedef enum {
	SUBMISSION_TYPE_NOW_PLAYING,
	SUBMISSION_TYPE_PROFILE
} SubmissionType;

typedef struct {
	StrBuf *sb;
	SubmissionType type;
} Submission;

Submission *submission_new (StrBuf *sb, SubmissionType type);
Submission *now_playing_submission_new (xmmsv_t *dict);
Submission *profile_submission_new (xmmsv_t *dict, uint32_t seconds_played, time_t started_playing);
Submission *submission_clone (Submission *s);
void submission_free (Submission *s);

#endif
