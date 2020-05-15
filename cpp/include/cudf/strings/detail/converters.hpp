/*
 * Copyright (c) 2020, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cudf/column/column.hpp>
#include <cudf/scalar/scalar.hpp>
#include <cudf/strings/strings_column_view.hpp>

namespace cudf {
namespace strings {
namespace detail {

/**
 * @copydoc to_integers(strings_column_view const&,data_type,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> to_integers(
  strings_column_view const& strings,
  data_type output_type,
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc from_integers(strings_column_view const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> from_integers(
  column_view const& integers,
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc to_floats(strings_column_view const&,data_type,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> to_floats(
  strings_column_view const& strings,
  data_type output_type,
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc from_floats(strings_column_view const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> from_floats(
  column_view const& floats,
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc to_booleans(strings_column_view const&,string_scalar
 * const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> to_booleans(
  strings_column_view const& strings,
  string_scalar const& true_string    = string_scalar("true"),
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc from_booleans(strings_column_view const&,string_scalar const&,string_scalar
 * const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> from_booleans(
  column_view const& booleans,
  string_scalar const& true_string    = string_scalar("true"),
  string_scalar const& false_string   = string_scalar("false"),
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc to_timestamps(strings_column_view const&,data_type,std::string
 * const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<cudf::column> to_timestamps(
  strings_column_view const& strings,
  data_type timestamp_type,
  std::string const& format,
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @copydoc from_timestamps(strings_column_view const&,std::string
 * const&,rmm::mr::device_memory_resource*)
 *
 * @param stream Stream on which to execute kernels.
 */
std::unique_ptr<column> from_timestamps(
  column_view const& timestamps,
  std::string const& format           = "%Y-%m-%dT%H:%M:%SZ",
  cudaStream_t stream                 = cudaStream_t{},
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

}  // namespace detail
}  // namespace strings
}  // namespace cudf
