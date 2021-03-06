/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_PROTO_DETACH_ROLE_HPP
#define IROHA_PROTO_DETACH_ROLE_HPP

#include "backend/protobuf/common_objects/trivial_proto.hpp"
#include "commands.pb.h"
#include "interfaces/commands/detach_role.hpp"

namespace shared_model {
  namespace proto {

    class DetachRole final : public CopyableProto<interface::DetachRole,
                                                  iroha::protocol::Command,
                                                  DetachRole> {
     public:
      template <typename CommandType>
      explicit DetachRole(CommandType &&command);

      DetachRole(const DetachRole &o);

      DetachRole(DetachRole &&o) noexcept;

      const interface::types::AccountIdType &accountId() const override;

      const interface::types::RoleIdType &roleName() const override;

     private:
      const iroha::protocol::DetachRole &detach_role_;
    };

  }  // namespace proto
}  // namespace shared_model

#endif  // IROHA_PROTO_DETACH_ROLE_HPP
