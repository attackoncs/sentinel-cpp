#pragma once

#include "sentinel-core/slot/base/stats_slot.h"

namespace Sentinel {
namespace Slot {

class StatisticSlot : public StatsSlot {
 public:
  StatisticSlot() = default;
  ~StatisticSlot() = default;

  TokenResultSharedPtr Entry(const EntryContextPtr& context,
                             const ResourceWrapperSharedPtr& resource,
                             /*const*/ Stat::NodePtr&, int count,
                             int flag) override;
  void Exit(const EntryContextPtr& context,
            const ResourceWrapperSharedPtr& resource, int count) override;

 private:
  TokenResultSharedPtr OnPass(const EntryContextPtr& context,
                              const ResourceWrapperSharedPtr& resource,
                              const Stat::NodePtr& node, int count, int flag);
  TokenResultSharedPtr OnBlock(const TokenResultSharedPtr& prev_result,
                               const EntryContextPtr& context,
                               const ResourceWrapperSharedPtr& resource,
                               const Stat::NodePtr&, int count, int flag);

  void RecordPassFor(const Stat::NodePtr& node, int count);
  void RecordBlockFor(const Stat::NodePtr& node, int count);
  void RecordCompleteFor(const Stat::NodePtr& node, int rt, int count);
};

}  // namespace Slot
}  // namespace Sentinel