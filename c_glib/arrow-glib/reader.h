/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include <arrow-glib/record-batch.h>
#include <arrow-glib/schema.h>

#include <arrow-glib/input-stream.h>

#include <arrow-glib/metadata-version.h>

G_BEGIN_DECLS

#define GARROW_TYPE_RECORD_BATCH_READER         \
  (garrow_record_batch_reader_get_type())
#define GARROW_RECORD_BATCH_READER(obj)                         \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),                            \
                              GARROW_TYPE_RECORD_BATCH_READER,  \
                              GArrowRecordBatchReader))
#define GARROW_RECORD_BATCH_READER_CLASS(klass)                 \
  (G_TYPE_CHECK_CLASS_CAST((klass),                             \
                           GARROW_TYPE_RECORD_BATCH_READER,     \
                           GArrowRecordBatchReaderClass))
#define GARROW_IS_RECORD_BATCH_READER(obj)                      \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),                            \
                              GARROW_TYPE_RECORD_BATCH_READER))
#define GARROW_IS_RECORD_BATCH_READER_CLASS(klass)              \
  (G_TYPE_CHECK_CLASS_TYPE((klass),                             \
                           GARROW_TYPE_RECORD_BATCH_READER))
#define GARROW_RECORD_BATCH_READER_GET_CLASS(obj)               \
  (G_TYPE_INSTANCE_GET_CLASS((obj),                             \
                             GARROW_TYPE_RECORD_BATCH_READER,   \
                             GArrowRecordBatchReaderClass))

typedef struct _GArrowRecordBatchReader      GArrowRecordBatchReader;
#ifndef __GTK_DOC_IGNORE__
typedef struct _GArrowRecordBatchReaderClass GArrowRecordBatchReaderClass;
#endif

/**
 * GArrowRecordBatchReader:
 *
 * It wraps `arrow::ipc::RecordBatchReader`.
 */
struct _GArrowRecordBatchReader
{
  /*< private >*/
  GObject parent_instance;
};

#ifndef __GTK_DOC_IGNORE__
struct _GArrowRecordBatchReaderClass
{
  GObjectClass parent_class;
};
#endif

GType garrow_record_batch_reader_get_type(void) G_GNUC_CONST;

GArrowSchema *garrow_record_batch_reader_get_schema(
  GArrowRecordBatchReader *reader);
GArrowRecordBatch *garrow_record_batch_reader_get_next_record_batch(
  GArrowRecordBatchReader *reader,
  GError **error);


#define GARROW_TYPE_RECORD_BATCH_STREAM_READER          \
  (garrow_record_batch_stream_reader_get_type())
#define GARROW_RECORD_BATCH_STREAM_READER(obj)                          \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),                                    \
                              GARROW_TYPE_RECORD_BATCH_STREAM_READER,   \
                              GArrowRecordBatchStreamReader))
#define GARROW_RECORD_BATCH_STREAM_READER_CLASS(klass)                  \
  (G_TYPE_CHECK_CLASS_CAST((klass),                                     \
                           GARROW_TYPE_RECORD_BATCH_STREAM_READER,      \
                           GArrowRecordBatchStreamReaderClass))
#define GARROW_IS_RECORD_BATCH_STREAM_READER(obj)                       \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),                                    \
                              GARROW_TYPE_RECORD_BATCH_STREAM_READER))
#define GARROW_IS_RECORD_BATCH_STREAM_READER_CLASS(klass)               \
  (G_TYPE_CHECK_CLASS_TYPE((klass),                                     \
                           GARROW_TYPE_RECORD_BATCH_STREAM_READER))
#define GARROW_RECORD_BATCH_STREAM_READER_GET_CLASS(obj)                \
  (G_TYPE_INSTANCE_GET_CLASS((obj),                                     \
                             GARROW_TYPE_RECORD_BATCH_STREAM_READER,    \
                             GArrowRecordBatchStreamReaderClass))

typedef struct _GArrowRecordBatchStreamReader      GArrowRecordBatchStreamReader;
#ifndef __GTK_DOC_IGNORE__
typedef struct _GArrowRecordBatchStreamReaderClass GArrowRecordBatchStreamReaderClass;
#endif

/**
 * GArrowRecordBatchStreamReader:
 *
 * It wraps `arrow::ipc::RecordBatchStreamReader`.
 */
struct _GArrowRecordBatchStreamReader
{
  /*< private >*/
  GArrowRecordBatchReader parent_instance;
};

#ifndef __GTK_DOC_IGNORE__
struct _GArrowRecordBatchStreamReaderClass
{
  GArrowRecordBatchReaderClass parent_class;
};
#endif

GType garrow_record_batch_stream_reader_get_type(void) G_GNUC_CONST;

GArrowRecordBatchStreamReader *garrow_record_batch_stream_reader_new(
  GArrowInputStream *stream,
  GError **error);


#define GARROW_TYPE_RECORD_BATCH_FILE_READER    \
  (garrow_record_batch_file_reader_get_type())
#define GARROW_RECORD_BATCH_FILE_READER(obj)                            \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),                                    \
                              GARROW_TYPE_RECORD_BATCH_FILE_READER,     \
                              GArrowRecordBatchFileReader))
#define GARROW_RECORD_BATCH_FILE_READER_CLASS(klass)                    \
  (G_TYPE_CHECK_CLASS_CAST((klass),                                     \
                           GARROW_TYPE_RECORD_BATCH_FILE_READER,        \
                           GArrowRecordBatchFileReaderClass))
#define GARROW_IS_RECORD_BATCH_FILE_READER(obj)                         \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),                                    \
                              GARROW_TYPE_RECORD_BATCH_FILE_READER))
#define GARROW_IS_RECORD_BATCH_FILE_READER_CLASS(klass)                 \
  (G_TYPE_CHECK_CLASS_TYPE((klass),                                     \
                           GARROW_TYPE_RECORD_BATCH_FILE_READER))
#define GARROW_RECORD_BATCH_FILE_READER_GET_CLASS(obj)                  \
  (G_TYPE_INSTANCE_GET_CLASS((obj),                                     \
                             GARROW_TYPE_RECORD_BATCH_FILE_READER,      \
                             GArrowRecordBatchFileReaderClass))

typedef struct _GArrowRecordBatchFileReader      GArrowRecordBatchFileReader;
#ifndef __GTK_DOC_IGNORE__
typedef struct _GArrowRecordBatchFileReaderClass GArrowRecordBatchFileReaderClass;
#endif

/**
 * GArrowRecordBatchFileReader:
 *
 * It wraps `arrow::ipc::RecordBatchFileReader`.
 */
struct _GArrowRecordBatchFileReader
{
  /*< private >*/
  GObject parent_instance;
};

#ifndef __GTK_DOC_IGNORE__
struct _GArrowRecordBatchFileReaderClass
{
  GObjectClass parent_class;
};
#endif

GType garrow_record_batch_file_reader_get_type(void) G_GNUC_CONST;

GArrowRecordBatchFileReader *garrow_record_batch_file_reader_new(
  GArrowSeekableInputStream *file,
  GError **error);

GArrowSchema *garrow_record_batch_file_reader_get_schema(
  GArrowRecordBatchFileReader *reader);
guint garrow_record_batch_file_reader_get_n_record_batches(
  GArrowRecordBatchFileReader *reader);
GArrowMetadataVersion garrow_record_batch_file_reader_get_version(
  GArrowRecordBatchFileReader *reader);
GArrowRecordBatch *garrow_record_batch_file_reader_get_record_batch(
  GArrowRecordBatchFileReader *reader,
  guint i,
  GError **error);

G_END_DECLS
