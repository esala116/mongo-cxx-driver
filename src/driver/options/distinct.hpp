// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "driver/config/prelude.hpp"

#include <cstdint>
#include <string>

#include "bson/document.hpp"
#include "driver/base/read_preference.hpp"
#include "stdx/optional.hpp"

namespace mongo {
namespace driver {
namespace options {

/// Class representing the optional arguments to a MongoDB distinct command
class LIBMONGOCXX_EXPORT distinct {

   public:
    /// Sets the maximum amount of time for this operation to run (server side) in milliseconds.
    ///
    /// @see http://docs.mongodb.org/manual/reference/operator/meta/maxTimeMS
    ///
    /// @param max_time_ms the max amount of time (in milliseconds)
    void max_time_ms(std::int64_t max_time_ms);

    /// The current max_time_ms setting.
    ///
    /// @see http://docs.mongodb.org/manual/reference/operator/meta/maxTimeMS
    ///
    /// @return the current max time (in milliseconds)
    const optional<std::int64_t>& max_time_ms() const;

    /// Sets the read_preference for this operation.
    ///
    /// @see http://docs.mongodb.org/manual/core/read-preference/
    ///
    /// @param rp the new read_preference
    void read_preference(class read_preference rp);

    /// The current read_preference for this operation.
    ///
    /// @see http://docs.mongodb.org/manual/core/read-preference/
    ///
    /// @return the current read_preference
    const optional<class read_preference>& read_preference() const;

   private:
    optional<std::int64_t> _max_time_ms;
    optional<class read_preference> _read_preference;

}; // class distinct

}  // namespace options
}  // namespace driver
}  // namespace mongo

#include "driver/config/postlude.hpp"
