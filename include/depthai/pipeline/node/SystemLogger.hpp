#pragma once

#include <depthai/pipeline/DeviceNode.hpp>

// shared
#include <depthai-shared/properties/SystemLoggerProperties.hpp>

namespace dai {
namespace node {

/**
 * @brief SystemLogger node. Send system information periodically.
 */
class SystemLogger : public NodeCRTP<DeviceNode, SystemLogger, SystemLoggerProperties> {
   public:
    constexpr static const char* NAME = "SystemLogger";

    SystemLogger(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);
    SystemLogger(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId, std::unique_ptr<Properties> props);

    /**
     * Outputs SystemInformation[S3] message that carries various system information
     * like memory and CPU usage, temperatures, ...
     * For series 2 devices outputs SystemInformation message,
     * for series 3 devices outputs SystemInformationS3 message
     */
    Output out{*this, "out", Output::Type::MSender, {{DatatypeEnum::SystemInformation, false}, {DatatypeEnum::SystemInformationS3, false}}};

    /**
     * Specify logging rate, at which messages will be sent out
     * @param hz Sending rate in hertz (messages per second)
     */
    void setRate(float hz);

    /**
     * Gets logging rate, at which messages will be sent out
     */
    float getRate();
};

}  // namespace node
}  // namespace dai
